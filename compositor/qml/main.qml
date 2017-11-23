import QtQuick 2.0
import QtWayland.Compositor 1.0

WaylandCompositor {
    id: comp

    property var applicationsRect: []
    property int newApplicationIndex: 0
    property var globalShellSurface: null

    ListModel {
        id: applicationsModel
    }

    Screen {
        id: waylandScreen
        compositor: comp
    }

    Component {
        id: chromeComponent
        ShellSurfaceItem {
            anchors.fill: parent
            onSurfaceDestroyed: {
                console.log("Destroy");
                waylandScreen.stack.pop();
                destroy();
            }

            onWidthChanged: handleResized()
            onHeightChanged: handleResized()
            function handleResized() {
                shellSurface.sendConfigure(Qt.size(width, height), 0);
            }
        }
    }

    Component {
        id: surfaceComponent
        WaylandSurface {
        }
    }

    Component {
        id: ttt
        SurfaceItem {}
    }

    QtWindowManager {
        id: qtWindowManager
        onShowIsFullScreenChanged: console.debug("Show is fullscreen hint for Qt applications:", showIsFullScreen)
        showIsFullScreen: true
    }

    WlShell {
        onWlShellSurfaceCreated: {
            var parent = ttt.createObject();
            console.log("onWlShellSurfaceCreated " +  waylandScreen + parent);
            chromeComponent.createObject(parent, { "shellSurface": shellSurface } );
            waylandScreen.stack.push( { item: parent, destroyOnPop: false });
        }
    }

    XdgShellV5 {
        property variant viewsBySurface: ({})
        onXdgSurfaceCreated: {
            var item = chromeComponent.createObject(defaultOutput.surfaceArea, { "shellSurface": xdgSurface } );
            viewsBySurface[xdgSurface.surface] = item;
        }
        onXdgPopupCreated: {
            var parentView = viewsBySurface[xdgPopup.parentSurface];
            var item = chromeComponent.createObject(parentView, { "shellSurface": xdgPopup } );
            viewsBySurface[xdgPopup.surface] = item;
        }
    }

    TextInputManager {
    }

    onSurfaceRequested: {
        var surface = surfaceComponent.createObject(comp, { } );
        surface.initialize(comp, client, id, version);
    }
}

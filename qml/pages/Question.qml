import QtQuick 2.0
import Sailfish.Silica 1.0


ListItem {
    contentHeight: col.height

    Column {
        spacing: 3
        id: col

        Label {
            color: Theme.primaryColor
            id: name
            text: intitule
        }


        TextSwitch {
            id: repA
            text: reponseA
            checked: isOneChecked()
        }

        TextSwitch {
            id: repB
            text: reponseB
            checked: isOneChecked()
        }

        TextSwitch {
            id: repC
            text: reponseC
            checked: isOneChecked()
        }

        TextSwitch {
            id: repD
            text: reponseD
            checked: isOneChecked()
        }
    }

    function isOneChecked() {

    }
}




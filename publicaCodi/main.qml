/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import MqttClient 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Desactivació del sistema d'accés")
    id: root
    color:"SeaGreen"

    Text {
            text:""
            id:codi
            visible: false
         }

    MqttClient {
        id: client        
        hostname: "10.244.59.173"
        port: portField.text
        //username: userField.text
        //password: pwdField.text
    }

    /* Conexió al broker */
    Component.onCompleted: {
            client.connectToHost()
        }

    function afegeixChar(nombre)
    {
        codi.text = codi.text+qsTr(nombre)
        msgField.text = codi.text
    }

    GridLayout {
        anchors.fill: parent
        anchors.margins: 10
        columns: 2


        TextField {
            id: portField
            Layout.fillWidth: true
            text: "1883"
            placeholderText: "<Port>"
            inputMethodHints: Qt.ImhDigitsOnly
            enabled: client.state === MqttClient.Disconnected
            visible: false
        }


        GridLayout {
            enabled: client.state === MqttClient.Connected
            Layout.columnSpan: 2
            Layout.fillWidth: true
            columns: 4

            Label {
                text: "Codi:"
            }

            TextField {
                id: msgField
                Layout.fillWidth: true
                background: Rectangle {
                                       radius: 2
                                       implicitWidth: 150
                                       implicitHeight: 60
                                       border.color: "#333"
                                       border.width: 1
                                       color:"silver"
                                   }
                font.pointSize: 29
            }

            Button {
                id: pubButton
                Layout.fillWidth: true
                text: "Envia"
                font.pointSize: 17
                palette {button: "chartreuse"}
                onClicked: {
                    client.publish(msgField.text,"0",false)
                }
            }
        }

        GridLayout
        {
            columns:10
            rows:4
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: bt1
                Layout.column:0
                Layout.row:0
                text: "1"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("1")
                }
            }
            Button {
                id: bt2
                Layout.column:1
                Layout.row:0
                text: "2"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("2")
                }
            }
            Button {
                id: bt3
                Layout.column:2
                Layout.row:0
                text: "3"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("3")
                }
            }
            Button {
                id: bt4
                Layout.column:3
                Layout.row:0
                text: "4"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("4")
                }
            }
            Button {
                id: bt5
                Layout.column:4
                Layout.row:0
                text: "5"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("5")
                }
            }
            Button {
                id: bt6
                Layout.column:5
                Layout.row:0
                text: "6"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("6")
                }
            }
            Button {
                id: bt7
                Layout.column:6
                Layout.row:0
                text: "7"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("7")
                }
            }
            Button {
                id: bt8
                Layout.column:7
                Layout.row:0
                text: "8"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("8")
                }
            }
            Button {
                id: bt9
                Layout.column:8
                Layout.row:0
                text: "9"
                font.pointSize: 17
                palette {button: "lightgreen"}
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("9")
                }
            }
            Button {
                id: bt0
                Layout.column:9
                Layout.row:0
                font.pointSize: 17
                palette {button: "lightgreen"}
                text: "0"
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("0")
                }
            }
            Button {
                id: bta
                Layout.column:0
                Layout.row:1
                text: "A"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("A")
                }
            }
            Button {
                id: btb
                Layout.column:1
                Layout.row:1
                text: "B"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("B")
                }
            }
            Button {
                id: btc
                Layout.column:2
                Layout.row:1
                text: "C"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("C")
                }
            }
            Button {
                id: btd
                Layout.column:3
                Layout.row:1
                text: "D"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("D")
                }
            }
            Button {
                id: bte
                Layout.column:4
                Layout.row:1
                text: "E"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("E")
                }
            }
            Button {
                id: btf
                Layout.column:5
                Layout.row:1
                text: "F"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("F")
                }
            }
            Button {
                id: btg
                Layout.column:6
                Layout.row:1
                text: "G"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("G")
                }
            }
            Button {
                id: bth
                Layout.column:7
                Layout.row:1
                text: "H"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("H")
                }
            }
            Button {
                id: bti
                Layout.column:8
                Layout.row:1
                text: "I"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("I")
                }
            }
            Button {
                id: btj
                Layout.column:9
                Layout.row:1
                text: "J"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("J")
                }
            }
            Button {
                id: btk
                Layout.column:0
                Layout.row:2
                text: "K"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("K")
                }
            }
            Button {
                id: btl
                Layout.column:1
                Layout.row:2
                text: "L"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("L")
                }
            }
            Button {
                id: btm
                Layout.column:2
                Layout.row:2
                text: "M"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("M")
                }
            }
            Button {
                id: btn
                Layout.column:3
                Layout.row:2
                text: "N"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("N")
                }
            }
            Button {
                id: bto
                Layout.column:4
                Layout.row:2
                text: "O"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("O")
                }
            }
            Button {
                id: btp
                Layout.column:5
                Layout.row:2
                text: "P"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("P")
                }
            }
            Button {
                id: btq
                Layout.column:6
                Layout.row:2
                text: "Q"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("Q")
                }
            }
            Button {
                id: btr
                Layout.column:7
                Layout.row:2
                text: "R"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("R")
                }
            }
            Button {
                id: bts
                Layout.column:8
                Layout.row:2
                text: "S"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("S")
                }
            }
            Button {
                id: btt
                Layout.column:9
                Layout.row:2
                text: "T"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("T")
                }
            }
            Button {
                id: btu
                Layout.column:0
                Layout.row:3
                text: "U"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("U")
                }
            }
            Button {
                id: btv
                Layout.column:1
                Layout.row:3
                text: "V"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("V")
                }
            }
            Button {
                id: btw
                Layout.column:2
                Layout.row:3
                text: "W"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("W")
                }
            }
            Button {
                id: btx
                Layout.column:3
                Layout.row:3
                text: "X"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("X")
                }
            }
            Button {
                id: bty
                Layout.column:4
                Layout.row:3
                text: "Y"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("Y")
                }
            }
            Button {
                id: btz
                Layout.column:5
                Layout.row:3
                text: "Z"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: root.width / 11
                onClicked: {
                    afegeixChar("Z")
                }
            }
            Button {
                id: btesp
                Layout.column:6
                Layout.columnSpan: 8
                Layout.row:3
                text: "esp"
                palette {button: "darkseagreen"}
                font.pointSize: 17
                Layout.preferredWidth: (root.width / 11 )*4.3
                onClicked: {
                    afegeixChar(" ")
                }
            }
        }

    }
}

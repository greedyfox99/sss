import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 400
    height: 450
    visible: true
    title: "后台日志查看器"

    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10

        Button {
            text: "开始执行 C++ 任务"
            width: parent.width
            onClicked: {
                console.log("QML: 点击按钮")
                backend.startWorking() // 调用 C++
            }
        }

        // ★ 核心重点：ListView 控件（列表视图）
        ListView {
            id: logListView
            width: parent.width
            height: parent.height - 60

            // 直接把 model 绑定到 C++ 的 logs 属性！
            model: backend.logs

            // 如何渲染列表里的每一行？
            delegate: Rectangle {
                width: logListView.width
                height: 30
                color: "transparent"

                Text {
                    text: modelData  // modelData 就是列表里的每一行文字
                    font.pixelSize: 14
                    color: "blue"
                }
            }
        }
    }
}

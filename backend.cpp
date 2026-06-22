#include "backend.h"
#include <QDebug>

Backend::Backend(QObject *parent) : QObject(parent), m_step(0)
{
    m_timer.setInterval(1000); // 每 1 秒执行一次
    connect(&m_timer, &QTimer::timeout, this, &Backend::updateTask);
}

void Backend::startWorking()
{
    if (m_timer.isActive()) return;
    m_logs.clear(); // 清空旧日志
    m_step = 0;
    emit logsChanged(); // 通知 QML 列表清空了
    m_timer.start();
    qDebug() << "C++: 任务开始";
}

void Backend::updateTask()
{
    m_step++;
    QString logText;
    if (m_step <= 3) {
        logText = QString("正在处理第 %1 步...").arg(m_step);
    } else if (m_step == 4) {
        logText = "所有任务执行完毕！";
        m_timer.stop(); // 停止定时器
    } else {
        return;
    }

    // 把新日志塞进列表
    m_logs.append(logText);
    // ★ 关键：通知 QML 列表变了，QML 才会自动显示新的一行
    emit logsChanged();
}

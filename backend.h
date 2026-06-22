#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QVariantList>
#include <QTimer>

class Backend : public QObject
{
    Q_OBJECT
    // ★ 新增：一个列表属性，让 QML 可以直接读它
    Q_PROPERTY(QVariantList logs READ logs NOTIFY logsChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    // 暴露给 QML 调用的方法
    Q_INVOKABLE void startWorking();

    // 读取列表属性的方法
    QVariantList logs() const { return m_logs; }

signals:
    void logsChanged(); // 列表变化时通知 QML

private:
    QTimer m_timer;
    int m_step;
    QVariantList m_logs; // 用来存日志的列表
    void updateTask();  // 定时器触发的普通函数
};

#endif // BACKEND_H

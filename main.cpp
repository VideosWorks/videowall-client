#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "videowallcontroller.h"

int main(int argc, char *argv[]) {

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	// Register custom models
	qmlRegisterType<VideoWallController>("nl.sensorlab.videowall", 1, 0, "VideoWallController");
	qmlRegisterUncreatableType<ConnectionState>("nl.sensorlab.videowall", 1, 0, "ConnectionState",
												 "Cannot create ConnectionState in QML");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

	if (engine.rootObjects().isEmpty()) {
		return -1;
	}

	return app.exec();
}

#include "animation.h"

#include <QDebug>

Animation::Animation(int id, const QString &name, const QString& description, QObject *parent) : QObject(parent) {
	_id = id;
	_name = name;
	_description = description;
	_active = false;

	connect(this, SIGNAL(activeChanged(bool)), this, SIGNAL(propertyUpdated()));
}

int Animation::id() const {
	return _id;
}

QString Animation::name() const {
	return _name;
}

QString Animation::description() const {
	return _description;
}

bool Animation::active() const {
	return _active;
}

void Animation::onActiveAnimationChanged(int activeAnimationId) {
	bool active = (activeAnimationId == _id);
	if (active != _active) {
		_active = active;
		emit activeChanged(_active);

	}
}

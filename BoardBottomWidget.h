#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "Player.h"
#include <memory>
#include "DataStore.h"
#include <QPainter>

class BoardProfileWidget : public QWidget {
public:
	BoardProfileWidget();
	~BoardProfileWidget();
	void Refresh();
private:
	QLabel *playerNameLabel;
	QLabel *playerPictureLabel;
	QGridLayout *gridLayout;
};

class BoardResourcePowerPlantWiget : public QWidget {
public:
	BoardResourcePowerPlantWiget();
	~BoardResourcePowerPlantWiget();
	void SetPowerPlantCard(std::shared_ptr<PowerPlantCard> powerPlantCard) { this->powerPlantCard = powerPlantCard; }
	void Refresh();
private:
	std::shared_ptr<PowerPlantCard> powerPlantCard;
	QGridLayout *gridLayout;
	std::vector<QLabel*> resourceLables;
	void paintEvent(QPaintEvent *e);
};

class BoardPlayerPowerPlantsWidget : public QWidget {
public:
	BoardPlayerPowerPlantsWidget();
	~BoardPlayerPowerPlantsWidget();
	void Refresh();
private:
	std::vector<BoardResourcePowerPlantWiget*> playerPowerPlantsWidgets;
	QGridLayout *gridLayout;
};

class BoardBottomWidget : public QWidget {
public:
	BoardBottomWidget();
	~BoardBottomWidget();
	void Refresh();
private:
	QGridLayout *gridLayout;
	BoardProfileWidget *boardProfileWidget;
	BoardPlayerPowerPlantsWidget *boardPlayerPowerPlantsWidget;
};

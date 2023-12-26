#pragma once
#include "AVLTree.hpp"
#include "ui_TabAVLT.h"
#include "TreeData.hpp"

#include <QWidget>
#include <QColor>

#include <random>

class TabAVLT: public QWidget, Ui::TabAVLT
{
	Q_OBJECT
protected:
	AVLTree<TreeData> tree;
	std::default_random_engine generator;
    std::uniform_int_distribution<int> random;

public:
	TabAVLT(QWidget *parent = nullptr);

public slots:
	void insert();
	void remove();
	void find();
};


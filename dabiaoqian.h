#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dabiaoqian.h"
#include <QMap>
#include "getnumbypanfu.h"
#include "QNetworkReply"

class dabiaoqian : public QMainWindow
{
	Q_OBJECT

public:
	dabiaoqian(QWidget *parent = Q_NULLPTR);
	void Init();
private:
	void checkDate();
	void ReadSignatue();
	QString ReadConf();
	void InitCombox();
	void UploadSignatureAndType();
	QString GetSignatureJson();
public slots:
	void UploadResponse(QNetworkReply* reply);
	void CheckResponse(QNetworkReply* reply);
	//void OnClickCheck();
	void OnClickNameType();
	void ComboxSelectIndexChange(int index);
	//void ComboxSigChange(int index);
private:
	Ui::dabiaoqianClass ui;
	
	QNetworkAccessManager *namUpload;
	QNetworkAccessManager *namCheck;
	//current select signature
	ULONG cur_signature;
	QString cur_type;
	QMap<int, QString> m_KeyMap;
	std::map<std::wstring, ULONG> sigmap;

};

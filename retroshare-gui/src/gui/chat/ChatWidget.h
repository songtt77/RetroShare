/****************************************************************
 *
 *  RetroShare is distributed under the following license:
 *
 *  Copyright (C) 2011, RetroShare Team
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/

#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

#include "gui/common/HashBox.h"
#include "ChatStyle.h"
#include "gui/style/RSStyle.h"

#include <retroshare/rsmsgs.h>

class QAction;
class QTextEdit;

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
	Q_OBJECT
    
public:
    enum enumChatType { TYPE_NORMAL, TYPE_HISTORY, TYPE_OFFLINE };

public:
	explicit ChatWidget(QWidget *parent = 0);
	~ChatWidget();

	void init(const std::string &peerId, const QString &title);

	bool hasNewMessages() { return newMessages; }
	bool isTyping() { return typing; }

	void focusDialog();
	void addToParent(QWidget *newParent);
	void removeFromParent(QWidget *oldParent);

	void addChatMsg(bool incoming, const QString &name, const QDateTime &sendTime, const QDateTime &recvTime, const QString &message, enumChatType chatType);
	void updateStatusString(const QString &statusMask, const QString &statusString);

	void addToolsAction(QAction *action);

	std::string getPeerId() { return peerId; }
	QString getTitle() { return title; }
	int getPeerStatus() { return peerStatus; }
	void setName(const QString &name);

	bool setStyle();
	const RSStyle *getStyle() { return &style; }

private slots:
	void clearChatHistory();
	void deleteChatHistory();
	void messageHistory();

signals:
	void infoChanged(ChatWidget*);
	void newMessage(ChatWidget*);

protected:
	bool eventFilter(QObject *obj, QEvent *event);
	virtual void showEvent(QShowEvent *event);
	virtual void resizeEvent(QResizeEvent *event);

private slots:
	void pasteLink();
	void contextMenu(QPoint);

	void fileHashingFinished(QList<HashedFile> hashedFiles);

	void smileyWidget();
	void addSmiley();

	void resetStatusBar() ;

	void addExtraFile();
	void addExtraPicture();
	void on_closeInfoFrameButton_clicked();

	void setColor();
	void getFont();
	void setFont();

	void sendChat();

	void updateStatus(const QString &peer_id, int status);
	void updatePeersCustomStateString(const QString& peer_id, const QString& status_string) ;

	bool fileSave();
	bool fileSaveAs();

private:
	void updateStatusTyping();
	void setCurrentFileName(const QString &fileName);

	void colorChanged(const QColor &c);
	void fontChanged(const QFont &font);
	void processSettings(bool load);

	std::string peerId;
	QString title;
	QString name;

	QColor currentColor;
	QFont  currentFont;

	QString fileName;

	bool newMessages;
	bool typing;
	int peerStatus;
	bool isChatLobby;

	time_t lastStatusSendTime;

	ChatStyle chatStyle;
	RSStyle style;

	Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
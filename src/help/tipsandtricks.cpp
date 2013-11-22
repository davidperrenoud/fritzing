/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2012 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 6112 $:
$Author: cohen@irascible.com $:
$Date: 2012-06-28 00:18:10 +0200 (Do, 28. Jun 2012) $

********************************************************************/

#include <QVBoxLayout>
#include <QPixmap>
#include <QIcon>
#include <QTime>

#include "tipsandtricks.h"

TipsAndTricks* TipsAndTricks::Singleton = NULL;
QList<TipSet *>  TipsAndTricks::TipSets;

TipsAndTricks::TipsAndTricks(QWidget *parent)
	: QDialog(parent)
{
	// Let's set the icon
	this->setWindowIcon(QIcon(QPixmap(":resources/images/fritzing_icon.png")));
	initTipSets();
	QString html("<html><body>");
	html += QString("<h3>%1</h3>").arg(tr("Fritzing Tips and Tricks"));
	html += "<ul>";
	foreach (TipSet * tipSet, TipSets) {
		html += QString("<li><h4>%1</h4><ul>").arg(tipSet->heading);
		foreach (QString tip, tipSet->tips) {
			html += QString("<li>%1</li>").arg(tip);
		}
		html += "</ul></li>";
	}
	html += "</ul>";
	html += "</body></html>"; 
	m_textEdit->setHtml(html);

	Singleton = this;
	setWindowTitle(tr("Tips and Tricks"));
	resize(400, 300);
	m_textEdit = new QTextEdit();
	m_textEdit->setReadOnly(true);

	QVBoxLayout * vLayout = new QVBoxLayout(this);
	vLayout->addWidget(m_textEdit);

}

void TipsAndTricks::initTipSets() {
	if (TipSets.count() > 0) return;

	QTime now = QTime::currentTime();
	qsrand(now.msec());

	TipSet * ts = new TipSet;
	ts->heading = tr("parts");
	ts->tips << tr("If you can't find a part in the Parts Bin, the Generic IC is your friend.  Drag it onto your sketch, then use the widgets in the Inspector to: choose from among 25 different through-hole and SMD packages; change the pin label; and--for DIPs and SIPs--change the number of pins.  You can also change the pin names with the Pin Label editor");
	ts->tips << tr("An icon in the parts bin may actually represent multiple related parts.  So when you drag an icon from the parts bin into a sketch, make sure you look at the inspector.  The inspector will display the range of choices available for you to modify a part, or swap it for a related part. The parts bin icon will also be a little 'stack' and not just a flat icon.");
	TipSets.append(ts);

	ts = new TipSet;
	ts->heading = tr("moving and selection");
	ts->tips << tr("To constrain the motion of a part to horizontal or vertical, hold down the shift key as you drag it.");
	ts->tips << tr("If you're having trouble selecting a part or a wire (segment), try selecting the part that's in the way and send it to the back: use the Raise and Lower functions on the Part menu or the context menu (right-click menu).");
	ts->tips << tr("To more precisely move a selection of parts, use the arrow keys.  Shift-arrow moves by 10 units.");
	TipSets.append(ts);

	ts = new TipSet;
	ts->heading = tr("curves and rubber band legs");
	ts->tips << tr("In Breadboard view, to drag a part with rubber-band legs while keeping it connected to the breadboard, hold the Alt (Linux: Meta) key down when you start dragging.");
	ts->tips << tr("In Breadboard view, to add a curve to a wire or rubber-band leg, drag with the Control (Mac: Command) key down.  You can set whether curvy wires are the default in Preferences.");
	ts->tips << tr("In Breadboard view, to drag out a wire from the end of a rubber-band leg, drag with the Alt (Linux: Meta) key down.");
	TipSets.append(ts);
	
	ts = new TipSet;
	ts->heading = tr("rotation");
	ts->tips << tr("To free-rotate a part in Breadboard or PCB view, select it, then hover your mouse near one of the corners until you see the rotate cursor. Mouse down and that corner will follow your mouse as you drag.");
	ts->tips << tr("To free-rotate a logo text or image item in PCB view hold down the Alt (Linux: meta) key and free-rotate as usual.");
	TipSets.append(ts);

	ts = new TipSet;
	ts->heading = tr("layers and views");
	ts->tips << tr("To drag the canvas, hold down the space bar and drag with the mouse.");
	ts->tips << tr("To toggle the visibility of layer in a view, go to the view menu and choose one of the view layer items.  Or open up the <b>Layers</b> palette from the <b>Window</b> menu.");
	ts->tips << tr("When you export images from Fritzing, you can choose which layers are exported. Before you choose 'Export...', go into the 'View' menu and hide the layers you don't want to be visible.");
	TipSets.append(ts);

	ts = new TipSet;
	ts->heading = tr("part labels");
	ts->tips << tr("To edit a part label, double-click it, or use the text input widget in the inspector window.");
	ts->tips << tr("To display different properties in a part label, as well as rotate it, or change the font, right-click the label.");
	ts->tips << tr("To move a part label independently from its part, select the part first--both the part and the label will be highlighted. Once the label is selected you can drag it.");
	TipSets.append(ts);

	ts = new TipSet;
	ts->heading = tr("wires and bendpoints");
	ts->tips << tr("To add a bendpoint to a wire, double-click where you want the bendpoint.");
	ts->tips << tr("To delete a bendpoint from a wire, double-click it.");
	ts->tips << tr("In Schematic or PCB view, if you drag from a bendpoint with the Alt (Linux: Meta) key down, you will drag out a new wire from that bendpoint.");
	ts->tips << tr("To drag a wire segment (a section of a wire between two bendpoints), drag it with the Alt (Linux: Meta) key down.  If you also hold down the shift key, the wire segment will be constrained to horizontal or vertical motion.");
	ts->tips << tr("Use shift-drag on a wire end or bendpoint to constrain its wire segment to an angle of 45 degrees (or some multiple of 45 degrees).  If the wire segment is connected to other wire segments, the segment you're dragging will snap to make 90 degree angles with the neighboring wire segment.");
	TipSets.append(ts);
}

TipsAndTricks::~TipsAndTricks()
{
}

void TipsAndTricks::hideTipsAndTricks() {
	if (Singleton != NULL) {
		Singleton->hide();
	}
}

void TipsAndTricks::showTipsAndTricks() {
	if (Singleton == NULL) {
		new TipsAndTricks();
	}

	Singleton->show();
}

void TipsAndTricks::cleanup() {
	if (Singleton) {
		delete Singleton;
		Singleton = NULL;
	}
}

const QString & TipsAndTricks::randomTip() {
	int tipCount = 0;
	foreach (TipSet * tipSet, TipSets) {
		tipCount += tipSet->tips.count();
	}
	int ix = qrand() % tipCount;
	tipCount = 0;
	foreach (TipSet * tipSet, TipSets) {
		int count = tipSet->tips.count();
		if (tipCount + count > ix) {
			return tipSet->tips.at(ix - tipCount);
		}
		tipCount += count;
	}

	// should not happen
	return ___emptyString___;
}
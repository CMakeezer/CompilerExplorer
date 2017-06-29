#include "ExplorerOutputPane.h"
#include "ExplorerOutputTable.h"
#include <QMessageBox>
#include <coreplugin/icore.h>
#include <QLineEdit>
#include <QToolButton>
#include <QLabel>
#include <QDebug>
namespace compilerExplorer {
namespace gui{
ExplorerOutputPane::ExplorerOutputPane(QObject *parent)
    : Core::IOutputPane(parent),
      mTableView(nullptr),
      mCompilerOptions(nullptr),
      mRunButton(nullptr),
      mBinary(nullptr),
      mLabel(nullptr),
      mDirectives(nullptr),
      mCommentOnly(nullptr),
      mIntel(nullptr) {
	createTableView();
	createCompilerOptions();
	createButtons();
}

ExplorerOutputPane::~ExplorerOutputPane() {
	delete mIntel;
	delete mCommentOnly;
	delete mDirectives;
	delete mLabel;
	delete mBinary;
	delete mRunButton;
	delete mCompilerOptions;
	delete mTableView;
}

void ExplorerOutputPane::runCompilerExplorer() {
	popup(0);
	QMessageBox::information(Core::ICore::mainWindow(),
	                         tr("Action Triggered"),
	                         tr("This is an action from CompilerExplorer."));

}

QWidget *ExplorerOutputPane::outputWidget(QWidget *parent) {
	Q_UNUSED(parent);
	return mTableView;
}

QList<QWidget *> ExplorerOutputPane::toolBarWidgets() const {
	QList<QWidget *> result;
	result << mRunButton << mCompilerOptions << mBinary << mLabel << mDirectives << mCommentOnly << mIntel;
	return result;
}

QString ExplorerOutputPane::displayName() const {
	return QString("Compiler Explorer");
}

int ExplorerOutputPane::priorityInStatusBar() const {
	return 1;
}

void ExplorerOutputPane::clearContents() {
}

void ExplorerOutputPane::visibilityChanged(bool visible) {
	Q_UNUSED(visible);
}

void ExplorerOutputPane::setFocus() {
	mTableView->setFocus();
}

bool ExplorerOutputPane::hasFocus() const{
	return mTableView->window()->focusWidget() == mTableView;
}

bool ExplorerOutputPane::canFocus() const {
	return true;
}

bool ExplorerOutputPane::canNavigate() const {
	return false;
}

bool ExplorerOutputPane::canNext() const {
	return false;
}

bool ExplorerOutputPane::canPrevious() const{
	return false;
}

void ExplorerOutputPane::goToNext() {
}

void ExplorerOutputPane::goToPrev() {
}

void ExplorerOutputPane::createTableView() {
	mTableView = new ExplorerOutputTable();
}

void ExplorerOutputPane::createCompilerOptions() {
	mCompilerOptions = new QLineEdit();
	mCompilerOptions->setPlaceholderText(tr("Compiler options..."));
}

void ExplorerOutputPane::createButtons() {
	mRunButton = createButton(tr("Run"),
	             tr("Send request"),false);
	mBinary = createButton(tr("11010"),
	             tr("Compile to binary and disassemble the output"));
	mLabel = createButton(tr(".LX0:"),
	             tr("Filter unused labels from the output"));
	mDirectives = createButton(tr(".text"),
	             tr("Filter all assembler directives from the output"));
	mCommentOnly = createButton(tr("//"),
	             tr("Remove all lines which are only comments from the output"));
	mIntel = createButton(tr("Intel"),
	                      tr("Output disassembly in Intel syntax"));
	connect(mRunButton, &QToolButton::clicked, this, &ExplorerOutputPane::onRunClicked);
}

QToolButton *ExplorerOutputPane::createButton(const QString &text, const QString &tooltip, bool checkable, const QIcon &icon) {
	auto btn = new QToolButton;
	btn->setText(text);
	btn->setToolTip(tooltip);
	btn->setCheckable(checkable);
	if(!icon.isNull()) {
		btn->setIcon(icon);
		btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
	}
	return btn;
}

void ExplorerOutputPane::onRunClicked() {
	qDebug() << "run clicked";
}

}
}
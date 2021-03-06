/****************************************************************************************
 ** QXmlGraphicReader is an application to open, edit and save XML configuration files.
 ** Copyright (C) 2013  Francesc Martinez <es.linkedin.com/in/cescmm/en>
 **
 ** This library is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public
 ** License as published by the Free Software Foundation; either
 ** version 2.1 of the License, or (at your option) any later version.
 **
 ** This library is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public
 ** License along with this library; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 ***************************************************************************************/

#include "FindDialog.h"
#include "ui_FindDialog.h"

FindDialog::FindDialog(QWidget *parent) : QWidget(parent), ui(new Ui::FindDialog)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);
    connect(ui->findButton, SIGNAL(clicked()), this, SLOT(findSlot()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::findSlot()
{
    QStringList filters;

    if (ui->cbTags->isChecked())
        filters.append("TAGS");
    if (ui->cbValues->isChecked())
        filters.append("VALUES");
    if (ui->cbAttributes->isChecked())
        filters.append("ATTRIBUTES");
    if (ui->cbCaseSensitive->isChecked())
        filters.append("CASE_SENSITIVE");

    emit findSignal(ui->LEFind->text(), filters);

    close();
}

/*
 * Copyright (c) 2018 Sune Vuorela <sune@vuorela.dk>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once
#include <QWidget>
#include <memory>

class QFileSystemModel;
class QAbstractProxyModel;
class QTreeView;
class FileNameTitleMapper;

/**
 * Pane for file system tree.
 */
class FsPane : public QWidget
{
    Q_OBJECT
public:
    FsPane(QWidget* parent = nullptr);
    ~FsPane();
    /**
     * Sets the root path for the file system pane to start from.
     *
     * \param string the root path
     */
    void setRootPath(const QString& string);
    /**
     * Provides a mapping from file path to title inside the file.
     *
     * Note: This causes model reset.
     *
     * \param titlemap map of file path -> title
     */
    void setFileNameTitleMap(QHash<QString,QString> titlemap);
Q_SIGNALS:
    /**
     * Emitted whenever a path is selected in this pane
     */
    void fileSelected(const QString& path);
private:
    std::unique_ptr<QFileSystemModel> m_dirModel;
    std::unique_ptr<QAbstractProxyModel> m_proxy;
    std::unique_ptr<FileNameTitleMapper> m_filenamemapper;
    QTreeView* m_tree;
    QString m_rootPath;
};

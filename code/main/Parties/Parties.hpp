#pragma once
#include "Party.hpp"

class NodeP
{
public:
    ItemP data;
    NodeP *left;
    NodeP *right;
    // Methods
    NodeP();
    NodeP(ItemP _data);
};

NodeP::NodeP()
{
    left = right = NULL;
}

NodeP::NodeP(ItemP _data)
{
    data = _data;
    left = right = NULL;
}

class PartiesBST
{
private:
    NodeP *root;
    long size;

    // methods private
private:
    bool isExistIDPrivate(NodeP *root, const long &_ID);
    bool isPaidPrivate(NodeP *root, const long &_ID);
    void addPrivate(NodeP *&root, ItemP val);                    // thêm node
    void printPreOrderPrivate(NodeP *root, const bool &_isPaid); // in duyệt đầu
    void printInOrderPrivate(NodeP *root);                       // in duyệt giữa
    void printPostOrderPrivate(NodeP *root);                     // in duyệt sau
    void freeMemory(NodeP *root);                                // giải phóng bộ nhớ
    ItemP returnNodePrivate(NodeP *root, const long &_ID);       // tìm node
    void updateNodePrivate(NodeP *&root, ItemP value);           // cập nhật node
    void findNodeSmallestPrivate(NodeP *&x, NodeP *&y);
    void removeNodePrivate(NodeP *&root, const long &_ID); // xoá node
    void exportPartiesDataPrivate(NodeP *root, ofstream &fileOut);
    Queue<long> getListID(NodeP *root); // lấy ds id

    // methods public
public:
    PartiesBST();  // hàm tạo
    ~PartiesBST(); // hàm huỷ
    NodeP *getRoot();
    long getSize();
    bool isExistID(const long &_ID);                  // kiểm tra trùng ID
    bool isPaid(const long &_ID);                     // kiểm tra đã thanh toán chưa
    void add(const ItemP &value);                     // thêm tiệc
    ItemP search(const long &ID);                     // tìm tiệc
    void update(const ItemP &value);                  // chỉnh sửa tiệc
    void remove(const long &ID);                      // xoá tiệc
    void display();                                   // xuất tất cả tiệc
    void displayByPaymentStatus(const bool &_isPaid); // xuất theo trạng thái thanh toán
    void importPartiesData(const string &_fileInPath);
    void exportPartiesData(const string &_fileOutPath);
};

// Methods private
bool PartiesBST::isExistIDPrivate(NodeP *root, const long &_ID)
{
    if (root == NULL)
        return false;
    if (root->data.getID() == _ID)
        return true;
    else
    {
        if (_ID < root->data.getID())
            return isExistIDPrivate(root->left, _ID);
        else if (_ID > root->data.getID())
            return isExistIDPrivate(root->right, _ID);
    }
    return false;
}

bool PartiesBST::isPaidPrivate(NodeP *root, const long &_ID)
{
    if (root == NULL)
        return false;
    if (root->data.getID() == _ID && root->data.getIsPaymentStatus())
        return true;
    else
    {
        if (_ID < root->data.getID())
            return isPaidPrivate(root->left, _ID);
        else if (_ID > root->data.getID())
            return isPaidPrivate(root->right, _ID);
    }
    return false;
}

void PartiesBST::addPrivate(NodeP *&root, ItemP val)
{
    if (root == NULL)
        root = new NodeP(val);
    else
    {
        if (val.getID() < root->data.getID())
            addPrivate(root->left, val);
        else if (val.getID() > root->data.getID())
            addPrivate(root->right, val);
    }
}

void PartiesBST::freeMemory(NodeP *root)
{
    if (root != NULL)
    {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
        size--;
    }
}

void PartiesBST::printPreOrderPrivate(NodeP *root, const bool &_isPaid)
{
    if (root != NULL)
    {
        printPreOrderPrivate(root->left, _isPaid);
        if (root->data.getIsPaymentStatus() == _isPaid)
            cout << root->data;
        printPreOrderPrivate(root->right, _isPaid);
    }
}

void PartiesBST::printInOrderPrivate(NodeP *root)
{
    if (root != NULL)
    {
        printInOrderPrivate(root->left);
        cout << root->data;
        printInOrderPrivate(root->right);
    }
}

void PartiesBST::printPostOrderPrivate(NodeP *root)
{
    if (root != NULL)
    {
        printPostOrderPrivate(root->left);
        printPostOrderPrivate(root->right);
        cout << root->data;
    }
}

ItemP PartiesBST::returnNodePrivate(NodeP *root, const long &_ID) // fix
{
    if (root != NULL)
    {
        if (_ID < root->data.getID())
            return returnNodePrivate(root->left, _ID);
        else if (_ID > root->data.getID())
            return returnNodePrivate(root->right, _ID);
        else
            return root->data;
    }
    return ItemP();
}

void PartiesBST::updateNodePrivate(NodeP *&root, ItemP value)
{
    if (root != NULL)
    {
        if (root->data.getID() == value.getID())
        {
            root->data = value;
            return;
        }
        else
        {
            if (value.getID() < root->data.getID())
                updateNodePrivate(root->left, value);
            else if (value.getID() > root->data.getID())
                updateNodePrivate(root->right, value);
        }
    }
}

void PartiesBST::findNodeSmallestPrivate(NodeP *&x, NodeP *&y) // Node *y = root->right
{
    // duyệt sang bên trái nhất
    if (y->left != NULL)
    {
        findNodeSmallestPrivate(x, y->left); // tìm ra node trái nhất
    }
    else // tìm ra được node trái nhất rồi (y->left == NULL)
    {
        x->data = y->data; // cập nhật cái data của node cần xoá chính là data của node thế mạng
        x = y;             // cho node x (là node mà chúng ta sẽ xoá đi sau này) cho node x trỏ đến node thế mạng ==> ra khỏi hàm thì sẽ xoá node x
        y = y->right;      // bản chất chỗ này chính là cập nhật lại mlk cho node cha của node thế mạng (mà chúng ta xoá) với node con của node thế mạng
    }
}

void PartiesBST::removeNodePrivate(NodeP *&root, const long &_ID)
{
    if (root == NULL)
        return;
    else
    {
        if (_ID < root->data.getID())
            removeNodePrivate(root->left, _ID);
        else if (_ID > root->data.getID())
            removeNodePrivate(root->right, _ID);
        else // đã tìm ra node cần xoá - root->data.getID() == _ID
        {
            // node x là node thế mạng - tí nữa xoá nó
            // xoá được cho cả node lá
            NodeP *x = root;
            if (root->left == NULL) // nếu nhánh trái NULL <=> đây chính là con phải
            {
                root = root->right; // duyệt sang phải của cái node cần xoá
                // để update mlk giữa node cha của node cần xoá với node con của node cần xoá
            }
            else if (root->right == NULL) // nếu nhánh phải NULL <=> đây là node có 1 con chính là con trái
            {
                root = root->left; // duyệt sang trái của cái node cần xoá
                // để update mlk giữa node cha của node cần xoá với node con của node cần xoá
            }
            else // node cần xoá là node có 2 con
            {
                // cách 1: Tìm node trái nhất của cây con phải (cây con phải của node cần xoá)
                NodeP *y = root->right; // node y là node thế mạng cho node cần xoá - node này sẽ đảm bảo nhận nhiệm vụ là tìm ra node trái nhất

                // cách 2: ngược lại với cách 1
            }
            delete x;
        }
    }
    size--;
}

void PartiesBST::exportPartiesDataPrivate(NodeP *root, ofstream &fileOut)
{
    if (root != NULL)
    {
        exportPartiesDataPrivate(root->left, fileOut);
        root->data.writeAParty(fileOut);
        exportPartiesDataPrivate(root->right, fileOut);
    }
}

Queue<long> PartiesBST::getListID(NodeP *root)
{
    Queue<long> listID;
    return listID;
}

// Methods public
PartiesBST::PartiesBST()
{
    root = NULL;
    size = 0;
}

PartiesBST::~PartiesBST()
{
    if (size == 0)
        return;
    freeMemory(root);
}

NodeP *PartiesBST::getRoot()
{
    return root;
}

long PartiesBST::getSize()
{
    return size;
}

bool PartiesBST::isExistID(const long &_ID)
{
    return isExistIDPrivate(root, _ID);
}

bool PartiesBST::isPaid(const long &_ID)
{
    return isPaidPrivate(root, _ID);
}

void PartiesBST::add(const ItemP &value)
{
    addPrivate(root, value);
    size++;
}

ItemP PartiesBST::search(const long &ID)
{
    return returnNodePrivate(root, ID);
}

void PartiesBST::update(const ItemP &value)
{
    updateNodePrivate(root, value);
}

void PartiesBST::remove(const long &ID)
{
    removeNodePrivate(root, ID);
}

void PartiesBST::display()
{
    long _ID;
    cout << "\n\t\t+=======================================================================================================================================+" << endl;
    cout << "\t\t|                                                          DANH SACH CAC TIEC                                                           |" << endl;
    cout << "\t\t+========+===============+=============================+==============+===================+========+===================+================+" << endl;
    cout << "\t\t|   ID   |   Thoi gian   |          Nguoi dat          |     SDT      |     Loai tiec     | So ban |  Trang thai tiec  |   Thanh toan   |" << endl;
    cout << "\t\t+========+===============+=============================+==============+===================+========+===================+================+";
    cout << "\t\t";
    printInOrderPrivate(root);

    // cout << "\n\t\t"
}

void PartiesBST::displayByPaymentStatus(const bool &_isPaid)
{
    long _ID;
    cout << "\n\t\t+=======================================================================================================================================+" << endl;
    cout << "\t\t|                                                          DANH SACH CAC TIEC                                                           |" << endl;
    cout << "\t\t+========+===============+=============================+==============+===================+========+===================+================+" << endl;
    cout << "\t\t|   ID   |   Thoi gian   |          Nguoi dat          |     SDT      |     Loai tiec     | So ban |  Trang thai tiec  |   Thanh toan   |" << endl;
    cout << "\t\t+========+===============+=============================+==============+===================+========+===================+================+";
    cout << "\t\t";
    printPreOrderPrivate(root, _isPaid);
}

void PartiesBST::importPartiesData(const string &_fileInPath)
{
    ifstream fileIn(_fileInPath);
    if (fileIn.is_open())
    {
        string newline;
        getline(fileIn, newline);
        while (!fileIn.eof())
        {
            ItemP _party;
            _party.readAParty(fileIn);
            add(_party);
        }
    }
    else
        cout << "\n\t\t(!) Loi khi mo file \"khachHang.txt\"" << endl;
    fileIn.close();
}

void PartiesBST::exportPartiesData(const string &_fileOutPath)
{
    ofstream fileOut(_fileOutPath);
    if (fileOut.is_open())
        exportPartiesDataPrivate(root, fileOut);
    else
        cout << "\n\t\t(!) Loi khi mo file \"khachHang.txt\"" << endl;
    fileOut.close();
}

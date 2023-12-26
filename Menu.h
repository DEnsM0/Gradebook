#include "Header.h"

namespace menu
{
    class Menu
    {
    public:

        using action_t = function<void()>;
        using action_b = function<bool()>;

        // ������������:
        Menu();
        Menu(const HANDLE&, string name = "���� ������� �����:", 
            string header = "��`�����-��������� ��������� ������� �������� ������");
        Menu(const Menu&) = default;
        Menu(Menu&&) = default;

        // ���������� �� �������������:
        ~Menu() = default;

        // �������������� ���������:
        Menu& operator= (const Menu&) = default;
        Menu& operator= (Menu&&) = default;

    public:
        // ������ ����� ����:
        void ChangeName(string);
        // ������ ������� ����:
        void CreateNewItem(string, action_t, action_b);
        // �������� ����:
        void Start();

    protected:
        // ������������ ����:
        void Init();
        // ������ ������� ����:
        void SelectItem(int);
        // ������� ��������� �� �������:
        void PrintHeader() const;
        // ������� ����� ���� �� �������:
        void PrintName() const;
        // ������� ���� �� �������:
        void PrintMenu() const;
        // ������� ������� �� �������:
        void PrintTooltip() const;
        // ������� ��-�� ���� �� �������:
        void PrintItems() const;
        // ���������� ������ �� �����:
        void SetToEnd();
        // ��������/������ ������:
        void ShowCursor(bool);
        // ��������� �������� ��������:
        int CheckVis();

    protected:
        // ��������� ��� �������� ����:
        struct MenuItem
        {
            // �����������:
            MenuItem(string name_, action_t action_, action_b bool_f, COORD position_ = COORD{})
                : name{ name_ }, action{ action_ }, vis{bool_f}, position{ position_ }
            {}
            // ���� �����:
            string name;
            action_t action;
            action_b vis;
            COORD position;
        };

    protected:
        // ������������� ��� �����:
        enum class Keys {
            Arrow = 224,
            ArrowUp = 80,
            ArrowDown = 72,
            Enter = 13,
            Escape = 27
        };
        // ���������� ������:
        HANDLE hConsole;
        // ������� ����:
        int position;
        // ����� ����:
        string menuName;

        string menuHeader;
        // ������� ����:
        string tooltip;
        vector<MenuItem> menuItems;


    };

}
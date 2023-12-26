#include "Header.h"
#include "Menu.h"

namespace menu
{
    Menu::Menu() :
        hConsole{},
        menuName{ "Меню:"},
        position{ 0 },
        tooltip{}
    {}
    Menu::Menu(const HANDLE& hConsole_, string name_, string header) :
        hConsole{ hConsole_ },
        menuName{ name_ },
        menuHeader{header},
        position{ 0 },
        tooltip{ "  Щоб вийти, натисніть \"Esc\"" }
    {
        ShowCursor(false);
    }

    void Menu::CreateNewItem(string name, action_t action, action_b vis)
    {
        menuItems.push_back(MenuItem(name, action, vis));
    }

    void Menu::Start()
    {
        if (menuItems.empty())
            return;

        system("cls");
        Init();
        // початковий елемент:
        SelectItem(0);

        // поточний код ключа:
        auto key = 0;

        // доки не натиснута клавіша Escape:
        while (key != static_cast<int>(Keys::Escape))
        {
            // отримати натиснуту клавішу:
            key = _getch();
            if (key == static_cast<int>(Keys::Enter))
            {
                { 
                    system("cls");
                    ShowCursor(true);

                    // виконання ф-ції елемента:
                    menuItems[position].action();
                    system("pause");

                    // перерисувати меню після натиснення клавіші:
                    system("cls");
                    ShowCursor(false);
                    PrintMenu();
                }
                SelectItem(position);
            }
            if (key != static_cast<int>(Keys::Arrow))
                continue;
            key = _getch();
            const auto selected = position;

            if (key == static_cast<int>(Keys::ArrowUp)) ++position;
            else if (key == static_cast<int>(Keys::ArrowDown)) --position;

            // у кінець:
            if (position < 0)
                position = menuItems.size() - 1;
            // на початок:
            else if (position > menuItems.size() - 1)
                position = 0;

            if (CheckVis() != -1 && position == CheckVis()) {
                if (position > menuItems.size() - 2 && selected != 0) position = 0;
                else if (position  < menuItems.size()) position = menuItems.size() - 2;
                else position = selected;
            }
            // вибір:
            if (selected != position)
                SelectItem(position);
        }
    }

    void Menu::ChangeName(string name)
    {
        menuName = name;
    }

    void Menu::Init()
    {
        menuHeader = "  " + menuHeader;
        menuName = "                   " + menuName;
        PrintHeader();
        PrintName();
        for (auto& item : menuItems)
            item.name = "              " + item.name;
        CONSOLE_SCREEN_BUFFER_INFO screenBuffer{};
        // запам'ятати позицію елемента:
        for (auto& item : menuItems)
        {
            GetConsoleScreenBufferInfo(hConsole, &screenBuffer);
            item.position = screenBuffer.dwCursorPosition;
            if (item.vis()) cout << item.name << endl;
        }
        PrintTooltip();
    }

    void Menu::SelectItem(int position)
    {
        for (auto& item : menuItems)
        {
            SetConsoleCursorPosition(hConsole, item.position);
            cout<<"              ";
            COORD pos = item.position;
            pos.X = item.name.size();
            SetConsoleCursorPosition(hConsole, pos);
            cout << "  ";
        }
        system("color 0F");
        SetConsoleCursorPosition(hConsole, menuItems[position].position);
        // виділення:
        SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
        cout << menuItems[position].name;
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        SetConsoleCursorPosition(hConsole, menuItems[position].position);
        cout << "            ->";
        COORD pos = menuItems[position].position;
        pos.X = menuItems[position].name.size();
        SetConsoleCursorPosition(hConsole, pos);
        cout << "<-";
        SetToEnd();
    }

    void Menu::SetToEnd()
    {
        SetConsoleCursorPosition(hConsole, menuItems[menuItems.size() - 1].position);
        cout << endl;
    }

    void Menu::PrintMenu() const
    {
        PrintHeader();
        PrintName();
        PrintItems();
        PrintTooltip();
    }

    void Menu::PrintTooltip() const
    {
        cout << endl << tooltip << endl;
    }
    void Menu::PrintName() const
    {
        cout << endl << menuName << endl << endl;
    }
    void Menu::PrintHeader() const
    {
        cout << menuHeader << endl ;
    }

    void Menu::PrintItems() const
    {
        for (auto& item : menuItems)
            if(item.vis())
            cout << item.name << endl;
    }

    void Menu::ShowCursor(bool visibility)
    {
        // зробити курсор видимим або ні:
        CONSOLE_CURSOR_INFO structCursorInfo;
        GetConsoleCursorInfo(hConsole, &structCursorInfo);
        structCursorInfo.bVisible = visibility;
        SetConsoleCursorInfo(hConsole, &structCursorInfo);
    }

    int Menu::CheckVis()
    {
        //перевірка видимості елементу меню:
        int val=0;
        for (auto& item : menuItems)
        {
            val++;
            if (!item.vis()) return val-1;
        }
        return -1;
    }
}
#include "Header.h"

namespace menu
{
    class Menu
    {
    public:

        using action_t = function<void()>;
        using action_b = function<bool()>;

        // конструктори:
        Menu();
        Menu(const HANDLE&, string name = "Меню залікової книги:", 
            string header = "Об`єктно-орієнтована програмна система «Залікова книжка»");
        Menu(const Menu&) = default;
        Menu(Menu&&) = default;

        // деструктор за замовчуванням:
        ~Menu() = default;

        // перевантаження операторів:
        Menu& operator= (const Menu&) = default;
        Menu& operator= (Menu&&) = default;

    public:
        // змінити назву меню:
        void ChangeName(string);
        // додати елемент меню:
        void CreateNewItem(string, action_t, action_b);
        // увімкнути меню:
        void Start();

    protected:
        // ініціалізувати меню:
        void Init();
        // обрати елемент меню:
        void SelectItem(int);
        // вивести заголовок на консоль:
        void PrintHeader() const;
        // вивести назву меню на консоль:
        void PrintName() const;
        // вивести меню на консоль:
        void PrintMenu() const;
        // вивести підказку на консоль:
        void PrintTooltip() const;
        // вивести ел-ти меню на консоль:
        void PrintItems() const;
        // встановити курсор на кінець:
        void SetToEnd();
        // показати/скрити курсор:
        void ShowCursor(bool);
        // перевірити видимість елементів:
        int CheckVis();

    protected:
        // структура для елементів меню:
        struct MenuItem
        {
            // конструктор:
            MenuItem(string name_, action_t action_, action_b bool_f, COORD position_ = COORD{})
                : name{ name_ }, action{ action_ }, vis{bool_f}, position{ position_ }
            {}
            // поля даних:
            string name;
            action_t action;
            action_b vis;
            COORD position;
        };

    protected:
        // перерахування для клавіш:
        enum class Keys {
            Arrow = 224,
            ArrowUp = 80,
            ArrowDown = 72,
            Enter = 13,
            Escape = 27
        };
        // дискриптор консолі:
        HANDLE hConsole;
        // позиція меню:
        int position;
        // назва меню:
        string menuName;

        string menuHeader;
        // підказка меню:
        string tooltip;
        vector<MenuItem> menuItems;


    };

}
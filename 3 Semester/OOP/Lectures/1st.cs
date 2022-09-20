/*                          ### Базовые знания ООП ###
ооп - парадигма программирования - как мы строим, определяем связываем
Императивное программирование - структурное программировагие, объектно ориентирование программировние.
Декларативное программироапние - логическое программирование, функциональное программирование

Что вызвало необходимость появления ооп?
сложные программы с богатым, динамичным функционалом, десятки и сотни иысяч кода -> десятки, сотни программистов -> ооп

Особенностб ооп
Центральное понятие ооп - КЛАСС
Класс - это объединение данных и операции с этими данными
Класс - это описание, схема, в соответствии с котторой в программе создаются, работают и уничттожаются экземпляры 

Преимущества ооп
легче расширять функционал
больше кода используется повторно
изменение функциональности затрагивают только классы, ответсвенные за  этот функционал 

Недостатки оопбольше времени и сил на проектирование
суммарно пишется больше кода */

using System;
using System.Drawing;
using System.Collections.Generic;

namespace ITMO_OOP
{
    public class Car
    {
        private Color _color; //приватный класс доступен только внешнему классу для использования - Car
                              //пример нейминга _colorCamelCase
        public Car(string manufacturer) : this(Color.White, manufacturer) { }
        //Эт конструктор - принимает производителя автомобиля - вызывает следующий конструктор:
        //this можно заменить на base - вызывает родителтский конструктор
        public Car(Color color, string manufacturer)
        {
            if (!IsColorAllowed(color)) throw new ArgumentOutOfRangeExeption(nameof(color));
            //IsColorAllowed - приватный метод объявлен дальше
            (_color, Manufacturer) = (color, manufacturer); //картеж - позволяет присваивать сразу несколько значений
            //Manufacturer - не поле а свойство ниже о нем
        }
        public string Manufacturer { get; } // свойство - объявление и поля  и доступа. Автоматическое свойство - 
                                            //компилятор создас сам метод get Manufactured - создаст возвращаемое поле 
                                            //get; set; - разрешаем не только читать значение свойства, но и устанавливать его

        public Color Color //не автоматическое свойство.
        {
            get => _color; //извне можно получить значение класса
                           // => позволяет просто вернуть значение без дополнительный штук
            private set //извне установить нельзя так как приватный
            {
                if (!IsColorAllowed(value)) return; //проверяем разрешен ли цвет, если нет то выходим

                var oldColor = _color;
                _color = value;
                ColorChanged?.Invoke(this, oldColor, value); //вызов собития (о нем ниже). ? - проверяет на nul
                                                             //если не nul вызывается метод Invoke
            }
        }

        public virtual bool ChangeColor(Color newColor)
        {
            var allowed = IsColorAllowed(newColor);
            if (allowed) Color = newColor;
            return allowed;
        }

        private static bool IsColorAllowed(Color color) => color != Color.Blue; //Запрещен синий цвет машины
        public delegate void ColorChangedHandler(Car car, Color oldColor, Color newColor); //делегат - сигнатура под которую подходит метод
        //событие - спрашиваем постоянно. Подписываясь на событие должны написать метод, делегат, который будет удовлетворять полям, диктуемых событием
        public event ColorChangedHandler ColorChanged;
    }


    //Теперь можем обращаться к методадам мейна. но они все должны быть статическими

    class Program
    {
        static void Main(string[] args)
        {
            Car blackVolvo = new(Color.Black, "Volvo");
            Car defaultMazda = new("Mazdda");
            Car blueFiat = null;

            try //пытаемся пррисвоить синий цвет, который под запретом
            {
                blueFiat = new Car(Color.Blue, "Fiat");
            }
            catch (ArgumentOutOfRangeExeption e)
            {
                Console.WriteLine($"Could not construct car! It has forbidden color. Exception: {e.Message}");
            }
            blackVolvo.ColorChanged += CarOnColorChanged;
            defaultMazda.ColorChanged += CarOnColorChanged;

            List<Car> cars = new() { blackVolvo, defaultMazda }; //просто список из наших машин

            ChangeCarsColor(cars, Color.Chocolate); //методы реализованные дальше
            ChangeCarsColor(cars, Color.Blue);
        }

        private static void ChangeCarsColor(IEnumerable<Car> cars, Color newColor)
        {
            foreach (var car in cars)
            {
                var oldColor = car.Color;
                var result = car.ChangeColor(newColor);
                Console.WriteLine($"we tried to changecolor of {car.GetHashCode()} from {oldColor.Name} to {newColor.Name}. Result: {(result ? "successful" : "failed")}");
            }
        }

        private static void CarOnColorChanged(Car car, Color oldColor, Color newColor)
        {
            Console.WriteLine($"Our car {car.GetHashCode()} manufactured by {car.Manufacturer} change color from {oldColor.Name} to {newColor.Name}");
        }
    }
}


/*Спросит на экзамене, если подумает что мы тупые совсем:
Класс - это шаблон для создания объектов, обисывающий, как объект устроен, из чего состоит, что и как он может делать.
Объект - экземпляр класса. Построенный по указанному в классе шаблону , способный выполнять конкретную работу.
В общем случае в программе одномоментно может существовать много объектов одного класса.*/
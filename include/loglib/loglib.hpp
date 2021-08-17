#ifndef LOGS_LIB_LOGLIB_HPP
#define LOGS_LIB_LOGLIB_HPP

#include <iostream>
#include <string>


class Logs{
public:
    /* Конструктор
     * Создает объект без пути к директории логов
     */
    [[maybe_unused]] Logs();
    /* Конструктор
     * Создает объект с путем к директории логов
     * @path: Путь к директории логов
     */
    [[maybe_unused]] explicit Logs(const std::string& dir);
    /* Конструктор копирования
     * Копирует объект
     * @&Logs: Копируемый объект
     */
    [[maybe_unused]] Logs(Logs &Logs);
    /* Конструктор перемещения
     * Перемещает объект
     * @&&Logs: Перемещаемый объект
     */
    Logs(Logs &&test) = default;
    /* Деструктор
     * Удаляет объект
     */
    ~Logs() = default;
    /* Метод set_path
     * Устанавливает путь к директории логов
     * @dir: Имя директории логов
     */
    [[maybe_unused]] void set_path(const std::string& dir);
    /* Метод get_path
     * Возвращает путь к директории логов
     * @return: std::string _path
     */
    std::string get_path();
    /* Метод get_current_path
     * Возвращает строку с путем к корневому каталогу
     * @return std::string _current_path
     */
    [[maybe_unused]] std::string get_current_path();

private:
    /* Функция поиска корневого каталога
     * Ищет корневой каталог
     * @return Возвращает строку с путем к корневому каталогу
     */
    std::string find_path();

    std::string _current_path {};  // Путь к корневому каталогу
    std::string _path {};          // Путь к директории файлов логов
    char _separator {};            // Разделительный знак
};

#endif //LOGS_LIB_LOGLIB_HPP

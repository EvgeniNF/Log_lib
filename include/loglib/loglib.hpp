#ifndef LOGS_LIB_LOGLIB_HPP
#define LOGS_LIB_LOGLIB_HPP

#include <iostream>
#include <string>


class Logs{
public:
    /* Конструктор
     * Создает объект без пути к директории логов
     */
    Logs() = default;
    /* Конструктор
     * Создает объект с путем к директории логов
     * @path: Путь к директории логов
     */
    [[maybe_unused]] explicit Logs(const std::string& path);
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
     * @path: Путь к директории логов
     */
    [[maybe_unused]] void set_path(std::string path);
    /* Метод get_path
     * Возвращает путь к директории логов
     * @return: std::string _path
     */
    std::string get_path();

private:
    std::string _path {};  // Путь к директории файлов логов

};

#endif //LOGS_LIB_LOGLIB_HPP

#ifndef LOGS_LIB_LOGLIB_HPP
#define LOGS_LIB_LOGLIB_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

class Logs{
public:
    /* Конструктор
     * Создает объект без пути к директории логов,
     * режим поумолчанию наладка
     */
    [[maybe_unused]] Logs();
    /* Конструктор
     * Создает объект с путем к директории логов,
     * режим поумолчанию наладка
     * @path: Путь к директории логов
     */
    [[maybe_unused]] explicit Logs(const std::string& dir);
    /* Конструктор
     * Создает объект с путем к директории логов,
     * и устанавливает режим @mode
     * @path: Путь к директории логов
     * @mode: Режим логирования 0 - Debug, 1 - Realise
     */
    [[maybe_unused]] explicit Logs(const std::string& dir, unsigned short int mode);
    /* Конструктор
     * Создает объект и устанавливает
     * режим @mode
     * @mode: Режим логирования 0 - Debug, 1 - Realise
     */
    [[maybe_unused]] explicit Logs(unsigned short int mode);
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
    /* Метод set_mode
     * Устанавливает режим логирования
     * @mode 0 - Debug, 1 - Realise
     */
    [[maybe_unused]] void set_mode(unsigned short int mode);
    /* Метод get_mode
     * Возвращает установленный режим
     * @return unsigned short int _mode
     */
    [[maybe_unused]] unsigned short int get_mode();
    /* Метод add_stream
     * Создает поток для вывода в лог файл
     * @name: Имя потока вывода
     */
    [[maybe_unused]] bool add_stream(const std::string& name);
    /* Метод get_streams
     * Возвращает имена потоков
     * @return: std::string
     */
    [[maybe_unused]] std::vector<std::string> get_streams();

private:
    /* Функция поиска корневого каталога
     * Ищет корневой каталог
     * @return Возвращает строку с путем к корневому каталогу
     */
    std::string find_path();

    std::map<std::string, std::ifstream> _logout {};  // Потоки вывода
    unsigned short int _mode = 0;  // Режим логирования 0 - Debug, 1 - Realise
    std::string _current_path {};  // Путь к корневому каталогу
    std::string _path {};          // Путь к директории файлов логов
    char _separator {};            // Разделительный знак
    const std::string _type_file = ".txt";  // Тип файла логов
};

#endif //LOGS_LIB_LOGLIB_HPP

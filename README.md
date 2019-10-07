![alert-banner](Docs/repo-banner.png?raw=true "Версия сырая! Ставить на свой СТРАХ и РИСК!")
* Баг №1 - произвольное движение каретки при печати

### Версия марлин - 2.0.x bugfix, взята 03.10.2019
![sapphire-pro-0-marlin-status](Docs/hints/sapphire-pro-2-marlin-status1.jpg?raw=true)

Собирать лучше всего с помощью Visual Studio Code + PlatformIO<br/>
[Инструкция по установке Visual Studio Code + PlatformIO](https://docs.platformio.org/en/latest/ide/vscode.html)<br/>

### Прошивка SapphirePro:
* После успешной сборки скопировать файл `Marlin2\.pio\build\mks_robin_nano\Robin_nano.bin` на sd карту
* Установить sd карту в принтер
* Включить/перезагрузить принтер
* Дождаться обновления

### Конфигурация прошивки
#### Configuration.h
  Конфигурация|Строка|Примечание
  ------------|------|----------
  PID|483|
  EXTRUDE_MAXLENGTH|569|
  Шаг и ускорение DEFAULT_AXIS_STEPS_PER_UNIT|730|
  Размер стола|1070|
  Сенсор окончания филамента FILAMENT_RUNOUT_SENSOR|1120|ВЫКЛ
  Калибровка стола MESH_BED_LEVELING|1186|
  Калибровка стола LCD_BED_LEVELING|1290|
  Калибровка стола LEVEL_BED_CORNERS|1299|
  Смещение "домашней" позиции MANUAL_X_HOME_POS MANUAL_Y_HOME_POS|1322|MANUAL_Z_HOME_POS: ВЫКЛ
  Настройка пред-нагрева PREHEAT_* |1458|PREHEAT_1_* : PET-G 215/75 PREHEAT_2_* : ABS 230/90
  Парковка хот-энда NOZZLE_PARK_FEATURE|1479|
  Язык интерфейса LCD_LANGUAGE|1600|Русский
  Проверка целостности чтения файлов SD_CHECK_AND_RETRY|1657|
  "Пищалка" SPEAKER|1728|При включении SPEAKER, **прошивка зависает!**
  
#### Configuration_adv.h
  Конфигурация|Строка|Примечание
  ------------|------|----------
  M73 прогресс LCD_SET_PROGRESS_MANUALLY|888|
  Отображение статуса|1143|
  Linear Advanced|1329|
  Ретракт|1580|пока ВЫКЛ
  Расширенная пауза|1639|
  FILAMENT_CHANGE_UNLOAD_LENGTH|1646|

### Графика
[Конвертер графики](http://marlinfw.org/tools/u8glib/converter.html)<br/>
`Marlin2\Marlin\_Bootscreen.h` - `Marlin2\Marlin\Configuration.h:91 #define SHOW_CUSTOM_BOOTSCREEN`<br/>
`Marlin2\Marlin\_Statusscreen.h` - `Marlin2\Marlin\Configuration.h:94 #define CUSTOM_STATUS_SCREEN_IMAGE`<br/>
Так же для модификации смотрите директорию `Pixmaps`<br/>

### Тюнинг PID
Нагреватель: `M303 E0 S200 C8`<br/>
Стол: `M303 E-1 C8 S90`<br/>

### Настройки ПО/слайсеров
  Конфигурация|Значение|Примечание
  ------------|----|------
  Скорость соединения с принтером|115200 бод|
  Размер стола|220х220 мм|Ни каких дополнительных смещений настраивать не надо
  Ретракт|8 мм|В заводских настройках указан 9мм
  Скорость ретракта|35-40 мм/c|

#### Пример настройки Repetier-Host
![sapphire-pro-bed-size-repetier](Docs/hints/sapphire-pro-bed-size-repetier.png?raw=true "Размер стола в Repetier-Host")

# Железо SapphirePro

* Дисплей - MKS TFT35 (3.5" (~9см)) 480*320<br/>
  Нашел нормальную реализацию масштабирования тут - https://github.com/inib/Marlin/tree/2.0.X-SapphirePro-3.5TFT<br/>
  https://escope.de/posts/sapphire-pro-marlin/<br/>

# Стоковые прошивки
`StockFirmwares`

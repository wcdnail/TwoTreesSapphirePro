# Marlin 2 bugfix для TwoTrees Sapphire Pro
## Версия марлин - 2.0.x bugfix, обновлена 10.10.2019
### Ставить на свой СТРАХ и РИСК!

# Внимание!
## Драйвера Z & E заменены на 2208
### Баг №1 - произвольное движение каретки при печати. **Перестал проявляться**. Буду проверять еще.

### С графикой помог Korbinian Heel
https://github.com/inib/Marlin/tree/2.0.X-SapphirePro-3.5TFT<br/>
https://escope.de/posts/sapphire-pro-marlin/<br/>

### Собирать лучше всего с помощью Visual Studio Code + PlatformIO
[Инструкция по установке Visual Studio Code + PlatformIO](https://docs.platformio.org/en/latest/ide/vscode.html)<br/>

### Прошивка SapphirePro:
* После успешной сборки скопировать файл `Marlin2\.pio\build\mks_robin_nano\Robin_nano.bin` на sd карту
* Установить sd карту в принтер
* Включить/перезагрузить принтер
* Дождаться обновления

### Конфигурация прошивки
#### Configuration.h
  Наименование                                                      |Строка |Примечание
  ------------------------------------------------------------------|-------|----------
  PID                                                               |    482|
  EXTRUDE_MAXLENGTH                                                 |    568|
  Константы драйверов                                               |    672|**Z_DRIVER_TYPE  TMC2208_STANDALONE** **E0_DRIVER_TYPE TMC2208_STANDALONE**
  Шаг и ускорение DEFAULT_AXIS_STEPS_PER_UNIT                       |    729|
  INVERT_ * _DIR                                                    |   1031|**INVERT_Z_DIR true** **INVERT_E0_DIR true**
  Размер стола                                                      |   1067|
  Сенсор окончания филамента FILAMENT_RUNOUT_SENSOR                 |   1117|ВЫКЛ
  Калибровка стола MESH_BED_LEVELING                                |   1183|
  Калибровка стола LCD_BED_LEVELING                                 |   1287|
  Калибровка стола LEVEL_BED_CORNERS                                |   1296|
  Смещение "домашней" позиции MANUAL_X_HOME_POS MANUAL_Y_HOME_POS   |   1319|MANUAL_Z_HOME_POS: ВЫКЛ
  Настройка пред-нагрева PREHEAT_*                                  |   1455|PREHEAT_1_* : PET-G 215/75 PREHEAT_2_* : ABS 230/90
  Парковка хот-энда NOZZLE_PARK_FEATURE                             |   1476|
  Язык интерфейса LCD_LANGUAGE                                      |   1588|Русский
  Проверка целостности чтения файлов SD_CHECK_AND_RETRY             |   1654|
  "Пищалка" SPEAKER                                                 |   1725|При включении SPEAKER, **прошивка зависает!**
  
#### Configuration_adv.h
  Наименование                                                      |Строка |Примечание
  ------------------------------------------------------------------|-------|----------
  HOMING_BACKOFF_MM                                                 |    524|ВЫКЛ
  HOME_AFTER_DEACTIVATE                                             |    647|ВЫКЛ
  M73 прогресс LCD_SET_PROGRESS_MANUALLY                            |    888|
  Отображение статуса                                               |   1144|
  Linear Advance                                                    |   1330|
  Ретракт                                                           |   1581|пока ВЫКЛ
  Расширенная пауза                                                 |   1640|
  FILAMENT_CHANGE_UNLOAD_LENGTH                                     |   1647|

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

# Стоковые прошивки
`StockFirmwares`

### Скрины
![sapphire-pro-3-marlin-status](Docs/hints-3/boot1.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/boot2.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/status.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/menu.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/about.jpg?raw=true)

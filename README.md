![alert-banner](Docs/repo-banner.png?raw=true "Версия сырая! Ставить на свой СТРАХ и РИСК!")
* Произвольное движение каретки при печати появляется после подключения принтера по USB (не всегда), предположительно это не связанно с Marlin

### Версия марлин - 2.0.x bugfix, взята 03.10.2019
![sapphire-pro-0-marlin-boot](Docs/hints/sapphire-pro-0-marlin-boot1.jpg?raw=true)
![sapphire-pro-0-marlin-status](Docs/hints/sapphire-pro-2-marlin-status1.jpg?raw=true)

Собирать лучше всего с помощью Visual Studio Code + PlatformIO<br/>
[Инструкция по установке Visual Studio Code + PlatformIO](https://docs.platformio.org/en/latest/ide/vscode.html)<br/>

### Прошивка SapphirePro:
* После успешной сборки скопировать файл `Marlin2\.pio\build\mks_robin_nano\Robin_nano.bin` на sd карту
* Установить sd карту в принтер
* Включить/перезагрузить принтер
* Дождаться обновления

### Конфигурация прошивки
  Конфигурация|Файл|Строка|Примечание
  ------------|----|------|----------
  PID|Marlin2\Marlin\Configuration.h|483|
  Шаг и ускорение DEFAULT_AXIS_STEPS_PER_UNIT|Marlin2\Marlin\Configuration.h|730|
  Размер стола|Marlin2\Marlin\Configuration.h|1070|
  Сенсор окончания филамента FILAMENT_RUNOUT_SENSOR|Marlin2\Marlin\Configuration.h|1120|ВЫКЛ
  MESH_BED_LEVELING|Marlin2\Marlin\Configuration.h|1186|
  LCD_BED_LEVELING|Marlin2\Marlin\Configuration.h|1290|
  Home offsets|Marlin2\Marlin\Configuration.h|1322|
  Парковка хот-энда NOZZLE_PARK_FEATURE|Marlin2\Marlin\Configuration.h|1479|
  M73 прогресс LCD_SET_PROGRESS_MANUALLY|Marlin2\Marlin\Configuration_adv.h|888|
  Отображение статуса|Marlin2\Marlin\Configuration_adv.h|1143|
  Linear Advanced|Marlin2\Marlin\Configuration_adv.h|1329|
  Ретракт|Marlin2\Marlin\Configuration_adv.h|1580|пока ВЫКЛ
  Расширенная пауза|Marlin2\Marlin\Configuration_adv.h|1639|

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

Дисплей - MKS TFT35 (3.5" (~9см)) 480*320<br/>

# Стоковые прошивки
`StockFirmwares`

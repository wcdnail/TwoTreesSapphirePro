# Marlin для TwoTrees Sapphire Pro
## Версия марлин - 2.1.x, обновлена 26.08.2022

### Внимание!
 - MarlinSP - теперь подмодуль git
 - MKS Robin Nano - STM32F103VET6
 - ~Баг №1 - произвольное движение каретки при печати~
 - Драйвера Z & E заменены на 2208
 - Настроен сенсор автоуровня емкостный
 - Настройки сохраняются в SPI Flash (см. Marlin2/src/HAL/HAL_STM32F1/persistent_store_spi_flash.cpp), спасибо [[@sobieh](https://github.com/sobieh)]
 - С графикой помог Korbinian Heel [[@inib](https://github.com/inib)] https://github.com/inib/Marlin/tree/2.0.X-SapphirePro-3.5TFT https://escope.de/posts/sapphire-pro-marlin/

### Собирать лучше всего с помощью Visual Studio Code + PlatformIO
[Инструкция по установке Visual Studio Code + PlatformIO](https://docs.platformio.org/en/latest/ide/vscode.html)<br/>

### Прошивка SapphirePro:
* После успешной сборки скопировать файл `MarlinSP\.pio\build\mks_robin_nano\Robin_nano.bin` на sd карту
* Установить sd карту в принтер
* Включить/перезагрузить принтер
* Дождаться обновления

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
  Скорость соединения с принтером|250000 бод|
  Размер стола|220х220 мм|Ни каких дополнительных смещений настраивать не надо
  Ретракт|8 мм|В заводских настройках указан 9мм
  Скорость ретракта|35-40 мм/c|

#### Пример настройки Repetier-Host
![sapphire-pro-bed-size-repetier](Docs/hints/sapphire-pro-bed-size-repetier.png?raw=true "Размер стола в Repetier-Host")

# Железо SapphirePro
 - Матплата - MKS Robin Nano STM32F103VET6
 - Дисплей - MKS TFT35 (3.5" (~9см)) 480*320<br/>

# Стоковые прошивки
`StockFirmwares`

### Скрины
![sapphire-pro-3-marlin-status](Docs/hints-3/boot1.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/boot2.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/status.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/menu.jpg?raw=true)
![sapphire-pro-3-marlin-status](Docs/hints-3/about.jpg?raw=true)

# Благодарность
## Команде разработчиков марлин
 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - USA &nbsp; [![Flattr Scott](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=thinkyhead&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - USA
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - USA
 - Chris Pepper [[@p3p](https://github.com/p3p)] - UK
 - João Brazio [[@jbrazio](https://github.com/jbrazio)] - Portugal
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)] - Netherlands &nbsp; [![Flattr Erik](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
## С графикой помог
 - Korbinian Heel [[@inib](https://github.com/inib)] https://escope.de/posts/sapphire-pro-marlin/
## EEPROM --> SPI Flash [[@sobieh](https://github.com/sobieh)]
 - https://github.com/inib/Marlin/pull/7
 

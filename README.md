# CityCraft

## Description

CityCraft is a city builder simulation where the user acts as the government of the city. CityCraft models a real life city to show the interaction of the government with componets like citizens, city construction and everything that goes with it. The goal of the program is to see your city grow and keep the lifeblood of the city, your citizens satsified.

## Table of Contents
- [Usage](#usage)
- [Game Menu](#game-menu)
  - [Main Menu](#main-menu)
    - [Building Menu](#building-menu)
      - [Residential Menu](#residential-menu)
      - [Commertial Menu](#commertial-menu)
      - [Industrial Menu](#industrial-menu)
      - [Utility Menu](#utility-menu)
      - [Landmark Menu](#landmark-menu)
      - [Infrastructure Menu](#infrastructure-menu)
    - [Government Menu](#government-menu)
      - [Taxation Menu](#taxation-menu)
      - [Polcies Menu](#policies-menu)
      - [Public Services Menu](#public-services-menu)
    - [Transportation](#transportation-menu)

## Usage

The usage of the program is ran by a game loop. The flow of the game is determined by the user. The user interacts with menus where they are guided to the desired destinations to execute their desires. When the program starts the first menu provides the user with an option to create a new game. After that they are directed to the main menu where they can select options like build buildings, go to government page, use transportation and view statistics. Each choice will open up a more specific menu catered to specific choice. The user will select an action to do for example Build Apartment and the changes will be shown in real time on their map. Each action has a consequence and can be reviewed to improve their gameplay to achieve a higher sitizen satisfaction while building their very own city.

## Game Menu

This is the first menu the user will interact with. Here they will start their game, by choosing the New Game option.

## Main Menu

The Main Menu is the core menu. This menu is where the actual gameplay starts. The user selects one of the options. Depending on what they want to do.

## Building Menu

This is the centered place for building to populate and grow the map.

## Residential Menu

Residential Menu is where concrete residential types can be selected. These types include: Apartment, House, TownHouse, Estate.

## Commertial Menu

Commertial Menu is where concrete commertial types can be selected. These types include: Store, Office, Mall.

## Industrial Menu

Industrial Menu is where concrete industrial types can be selected. These types include: Factory, Warehouse, Manufacturer.

## Utility Menu

Industiral Menu is where concrete utility types can be selected. These types include: Power Plant, Water Supply, Sewage Plant, Landfill.

## Landmark Menu

Landmark Menu is where concrete landmark types can be selected. These types include: Park, Monument, Cultural Center.

## Infrastructure Menu

Infrastructure Menu is where concrete infrastructure types can be selected. These types include: Road, Railway.

## Government Menu

This menu is used for taxation, implementing policies and managing public services.

## Taxation Menu

In this menu the user can increase or decrease the personal and business tax rate. Depending on their choice of what they feel is the best tax system to use. Personal and business tax can also be collected here.

## Policies Menu

The Polcies menu is where the user can implement different policies if they have the funds for it. You come to this menu to boost either your education, police or healthcare public service.

## Public Services Menu

This is the menu the user uses to manage the funds delegated to public services. The user can increase or decrease the funds of the public services.

## Transportation Menu
This function presents a menu to help the user select a transportation method based on their desired travel distance and group size. It guides the user through a sequence of steps.

Enter Travel Distance: Prompts for a positive integer distance in kilometers.

Enter Group Size: Prompts for the number of people traveling. Input is validated as a positive integer.

Display Transport Options: Based on the distance and capacity, the function lists available transport methods:

For distances 0-150 km: options include car, taxi, and train.
For distances over 150 km: airplane is also available.
Options are shown only if the capacity fits within the limits for each transport type.
Choose Transport Option: The user selects a transport method, which is then applied to the Statistics object to calculate the estimated cost and duration.

Show Travel Details: Displays the estimated cost and duration of the trip. Asks the user to confirm whether to proceed.

Confirm Travel: If the user confirms, it displays a message that the journey has begun; otherwise, it notifies that the travel was canceled.



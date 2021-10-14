# so_long

This is a small 2D game that let's you control a cat on its journey to collect the most sushi possible with as little effort as possible.

## Install

* Prerequisites: 
so_long requires the X11 Windowing System to work (this has been tested on Ubuntu 20.04 and worked just fine).

* Compilation:
After cloning the repo, you can use `Make` to create the executable for so_long.

## Running so_long

Once you've compiled the executable, you can start a game with this command:

```shell
./so_long "path to a map file"
```

Some default map files are available in the `/ber` directory.

## Making your own map

You can run so_long with your own map file as long as you respect these rules:
- file must end with the `.ber` extension.
- Map must only contain the following characters:

Symbol | Description
:---: | :---:
`1` | wall
`0` | empty space
`P` | Player position (there can't be more or less than one)
`C` | Collectible sushi (there needs to be at least one)
`E` | Exit (there needs to be at least one)

- Map must be surrounded by walls.
- Map must be rectangular.

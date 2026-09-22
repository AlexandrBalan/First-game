# Getting Started

## Prerequisites

The only things you need for this tutorial are a web browser and a GitHub account. 
If you don't already have a GitHub account, in a new tab go to [GitHub Signup](https://github.com/signup).
After you've logged in to GitHub, you're ready to begin the tutorial.

## Creating the Codespace

A Codespace is a GitHub feature that lets you explore a GitHub repository, create and modify files, and run code from your web browser. 
It's free up to a generous quota of usage and doesn't require any downloads or manual setup.

1. Open https://github.com/alope107/gba-quickstart in a new tab, and keep this tutorial open for reference.
1. On the **gba-quickstart** repository page, click the green "Use this template" button near the upper right of the window.
1. Select "Create a new repository." This creates a copy of the files in a new repository under your own GitHub username.
1. Name the repository what you want to call your game and add an optional description. Leave the other options at their default values.
1. Click "Create repository" and wait a few moments for the repository to be generated. When it's finished, refresh the page. You'll then see the same files that were in **gba-quickstart**, now copied to your own repository. 
1. Click the green "Code" button at the top right of the file list. In the popup, switch to the "Codespaces" tab and click "Create codespace on main."
1. The Codespace opens and starts to build in a new tab. The first time you do this for a repository it takes about 2-5 minutes. It'll be faster when you re-open the Codespace later.
1. If you are asked whether you trust the authors of the repository, click the green button to say yes.

Your Codespace is finished building when you see a list of files on the side, a README.md file in the center view, and a terminal at the bottom of the screen.
   
## Compiling the sample game

You'll run commands in the Codespace terminal to compile the game so you can run it. When you create the Codespace, its working directory (folder) is `/workspaces/NAME-OF-YOUR-GAME`, also known as the root directory of your repository. You have other directories (folders) in your repository, the most important of which is `game/`. 


1. In the left view panel, you can click the arrow next to the `game/` directory to open it and see the files inside.
1. In the terminal at the bottom, type `cd game` and hit Enter to move the working directory to the `game/` directory so you can compile the files there.
1. Type `make` and hit Enter. This compiles the game files into a ROM, a playable Game Boy Advance game. It will take about a minute for this demo game.

This process takes a minute or so because it's the first time the game has been compiled. 
If you make changes and compile again, it'll be faster because it'll only have to compile what was changed.
When the compile step is finished, you'll see a new file under the `game/` directory called `game.gba`, and also some other files that you can ignore.

## Running the sample game

1. Find the file `game.gba` underneath the `game/` directory on the left side of your screen.
1. Click on `game.gba`. In the center of your screen, a "Start Game" button will appear.
1. Click the "Start Game" button. In a few seconds the game will start. Use the arrow keys to move the dot around!
   
## Making changes to the sample game code

1. In the left file picker, choose `game/src/Main.cpp` (expand the `game/` folder, expand the `src/` folder and click on `Main.cpp`) to open it in the main view window. This file holds the game logic.

You'll make two changes: changing the backdrop color and changing the speed at which the sprite moves. 

1. Find the line of code in `Main.cpp` where the backdrop color is set. Instead of `(0, 0, 0)` (black), change it to `(31, 0, 0)` (red).
1. Find the line where the speed is set. Change the speed from `1.5` to `5.5`.

Each time you want to test changes to the code, you need to recompile the ROM. 

1. Check that the terminal is still in the `game` directory (`game` should show up as the end of the path).
1. Type `make` and hit Enter to rebuild the game with your new changes. If it fails, check the error message to see if there were any mistakes in the code you changed, like a missing comma or bracket.
1. Find the tab near the top of the editor that has the old version of the `game.gba` running in it. Close the old version of the game.
1. Click on the the `game.gba` file in the file explorer and click "Start Game" again. You should see the modified version of your game! Play around with arrow keys again.

Even though you've made changes in your Codespace and compiled the new ROM, everything gets deleted when a Codespace disappears.
Continue the tutorial to save your changes permanently.

## Committing and pushing your changes

You've made some valuable changes and it's important to make sure those changes are saved. 
In GitHub Codespaces, you should always both **commit** and **push** your changes frequently to avoid losing your work. 
If you delete a codespace and it has unpushed changes, they are lost forever!

If you're familiar with git, you can use your normal command-line workflow in the Codespace terminal to add/commit/push your changes as you would in any repository. 
If you're new to git, you can do the same things with the git plugin in Codespaces. 

1. On the left of your editor there should be an icon with a couple of circles, one of them blue with a number in it. If you hover over it, it should say "Source Control." Click that icon. The icon should look something like this:
    
    ![git file Icon](media/gitIcon.png)
1. The sidebar will show that `Main.cpp` is changed. Click the plus sign that appears to the right of it so that it moves to the "Staged Changes" sidebar section.
1. Above the Commit button, write a short message describing your changes, like "Changed background to red and increased player speed."
1. Click the Commit button.
1. Click on the new Sync Changes button that shows up. Click OK if there's an additional popup.

Great! You've pushed your changes!
**Make sure to do this each time you make a new update to your game.**
This makes sure you have your changes saved, even if you delete the codespace. 
If you're unhappy with a commit, you can also undo or revert commits to go back to a previous snapshot of your game development. 

## Editing a game sprite

You've already edited the game logic by modifying `Main.cpp`. Now, you'll edit the player sprite (pixel graphic). 

1. Switch back to the file picker view on the left by clicking the icon with the sheets of paper. It should look something like this:
    ![vscode file icon](media/fileIcon.png)
1. In the file picker go to `game`, then `graphics`. Click on the `dot.bmp` file.
1. A sprite editor will appear. Click a color on the right, and click on the sprite to edit it. Add a smiley face to the dot, or dress it up however you want! The changes will autosave in the Codespace.
1. Once you're done editing your sprite, go back to the terminal at the bottom of the screen. make sure you're in the `game/` directory, then type `make` and hit Enter.
1. This will recompile the game, including your new changes from the sprite.
1. Under the `game/` directory find `game.gba` again. Click on it again to see the new version of your game. It should have your new sprite in it!

Remember, even though your sprite change appears in the Codespace, it hasn't been committed and pushed to the repository yet. 
Follow the same steps from the previous section to commit and push the changes you made to `dot.bmp`.

## Exploring Butano Examples

Congratulations! You are now a Game Boy Advance homebrew developer! 
There is a lot more to learn, but you're well on your way. 
Butano comes preloaded with a number of examples you can find in `third_party/butano/examples`. 
You can compile them one at a time by navigating your terminal to one of those example directories and running `make`. 
Afterward, you can open the new `gba` file to test it out.

When you want to return to your codespace later, go back to your repository, click on the green Code button again, select Codespaces. 
You should see your existing Codespace still there for you to pick up where you left off.

## Going further

This tutorial is meant to be a quick introduction to whet your appetite. This online editor is convenient, but there are better options if you want to keep developing further. Some options:

### GBA Scenic Route

Interested in learning more about C++ GBA development and Butano at a higher level, similar to the code in this tutorial? Try out the [GBA Scenic Route](https://auberonedu.github.io/gba-scenic-route/) tutorial! It is a beginner focued tutorial that will walk you through setting up a full development environment (though still mostly automated with a devcontainer) and getting the games running on a real Game Boy Advance. It will help you understand how the example you just modified works, and will lead you through techniques to make more sophisticated games.

Note that this is VERY much so a work in progress. There is much unfinished, though it will continue to be developed.

If you're not sure what option to start with, begin here!

[GBA Scenic Route](https://auberonedu.github.io/gba-scenic-route/)

### Tonc

Looking for something lower-level, but less beginner friendly? Check out [tonc](https://gbadev.net/tonc/foreword.html). An amazing, mature tutorial in C that builds concepts from the bottom up.

If the code in this example felt too far away from the hardware, this is the place to go next.

[tonc](https://gbadev.net/tonc/foreword.html).


## Additional Resources

- [Butano Docs](https://gvaliente.github.io/butano/)
- [GBA Dev Discord](https://discord.gg/ctGSNxRkg2)
- [GBA Dev Site](https://gbadev.net/)

The GBA Dev Discord is an excellent place to get help developing your game. 
If you run into problems with this environment itself, e.g. the emulator or LibreSprite doesn't work, please [open an issue here](https://github.com/alope107/gba-quickstart/issues). 
As a short-term fix, you can try deleting your codespace and restarting it to see if that fixes the issue. 
JUST MAKE SURE YOU'VE COMMITTED AND PUSHED ANY CHANGES YOU WANT TO SAVE!

Have fun! More tutorials may be added later to help you learn more.

## Appendix: Terminal command reference

- `pwd`: **P**rint **W**orking **D**irectory. Run `pwd` to print a line to the terminal showing you the directory your terminal window is running commands in.
- `cd`: **C**hange **D**irectory. Type the directory after `cd` to move your terminal's working directory there.
  - `cd game`: Navigates to the directory `game/` if `game/` is under your working directory, otherwise prints an error because it can't find it.
  - `cd ..`: Navigates to the parent directory, or in other words whatever directory holds your working directory.
- `git add FILE-PATH`: Stages a file to get ready for a commit to git.
  - `git add Main.cpp`: Stages `Main.cpp` if it's under your working directory, otherwise prints an error because it can't find it.
  - `git add .`: Stages every modified file, no matter the location.
- `git commit -m "MESSAGE"`: Commits all the files you've staged, with a message to label the commit.
- `git push`: Pushes your changes to the repository.

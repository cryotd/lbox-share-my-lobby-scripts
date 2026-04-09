# LMAOBOX Premium: Share My Lobby Scripts
A collection of snippets for interacting with the lobby sharing backend of LMAOBOX Premium, a video game cheat for team fortress 2.
For more details, check out my [post](https://blog.drof.space/2026/04/07/lmaobox-premium-https-api-analysis/) about it.

Example output you can receive from lmaobox.net/sl/v:
```
7150b2f;4;1;eu;wesley; 2da5ef41;2;2;eu;xiong liqin baws; 66165030;1;1;eu;pikio;
```
Try it out [here](https://drof.space/tnv1a/lbox-share-my-lobby.php)


The two python files allow you to register with the party sharing service. You first need to construct a hex string based on a couple input parameters. 
```
i:  SteamID32 in hexadecimals
n:  in-game name to be displayed in other lmaobox user's lobby tab

and 2 other fields which control the play style/lobby type indicators
(numeric mappings for mvm,rage,casual,competitive), and lobby active player count, and the region of the host player.
```
You can utilize it to load arbitrary profiles into share my lobby, and make it appear to other lmaobox premium users who make use of party sharing service. https://www.youtube.com/watch?v=OXlZCJM2m6I

You can also use it to collect information about people who are participating in this specific cheat ecosystem's backend features. Check fetch-registration-table-active-users.cs for that.

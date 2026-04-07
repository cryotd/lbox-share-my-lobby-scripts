# LMAOBOX Premium: Share My Lobby Scripts
A collection of snippets for interacting with the lobby sharing backend of LMAOBOX Premium, a video game cheat for team fortress 2.


The two python files allow you to register with the party sharing service. You first need to construct a hex string based on a couple input parameters. 
```
i:  SteamID32 in hexadecimals
n:  in-game name to be displayed in other lmaobox user's lobby tab

and 2 other fields which control the play style/lobby type indicators
(numeric mappings for mvm,rage,casual,competitive), and lobby active player count, and the region of the host player.
```
You can utilize it to load arbitrary profiles into share my lobby, and make it appear to other lmaobox premium users who make use of party sharing service. https://www.youtube.com/watch?v=OXlZCJM2m6I

You can also use it to collect information about people who are participating in this specific cheat ecosystem's backend features. Check fetch-registration-table-active-users.cs for that.

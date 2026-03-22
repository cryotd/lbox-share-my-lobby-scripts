# LMAOBOX Premium: Share My Lobby Scripts
A collection of snippets for interacting with the lobby sharing backend of LMAOBOX Premium, a video game cheat for team fortress 2.

The two python files allow you to register with the party sharing service. You first need to construct a hex string based on a couple input parameters. 
```
i:  SteamID32 in hexadecimals
n:  in-game name to be displayed in other lmaobox user's lobby tab
and 2 other fields which control the play style/lobby type indicators
(numeric mappings for mvm,rage,casual,competitive), and lobby active player count, and the region of the host player.
```

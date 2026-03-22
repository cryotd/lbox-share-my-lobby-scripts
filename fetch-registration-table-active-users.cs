public sealed class CoordinatorRecord
{
    public string CoordinatorId { get; set; } = "";
    public int PartyMembersPresent { get; set; }
    public LobbyType LobbyType { get; set; }
    public string PlayerRegion { get; set; } = "";
    public string PlayerName { get; set; } = "";
}

public async Task<List<CoordinatorRecord>?> FetchRecordsAsync(CancellationToken cancellationToken)
{
    byte[] vecData =
    {
       // insert your extracted identity provider here. you can get it by taking a look at the cheat module lmaobox injects into the game.
       // it's simply a bitwise NOT performed on (customer email+customer full password) and then bitwise NOT on all of that.
    };

    byte[]? vecResponse = await PostBinaryAsync(
        "https://lmaobox.net/sl/v",
        vecData,
        cancellationToken
    );

    if (vecResponse is null || vecResponse.Length == 0)
        return null;

    byte[] decodedBytes = DecodeLobbyTable(vecResponse);
    string decoded = Encoding.Latin1.GetString(decodedBytes);

    int nullIndex = decoded.IndexOf('\0');
    if (nullIndex >= 0)
        decoded = decoded[..nullIndex];

    return ParseRecords(decoded);
}

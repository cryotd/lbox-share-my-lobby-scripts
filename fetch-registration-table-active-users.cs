public sealed class CoordinatorRecord
{
    public string CoordinatorId { get; set; } = ""; // Steam32-UID encoded in hex
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
       // 1
//Raw formatted buffer: i=47A2BE&amp;u=lboxuser@gmail.com
//u = customer email address
//i = some hardcoded string within the cheat payload (could be user identity related and embedded by their custom pipeline, no idea)
// perform a Bitwise NOT transform on this buffer, and boom you got your authentication data.
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

 private static byte[] DecodeLobbyTable(byte[] data)
 {
     var result = new byte[data.Length];

     for (int i = 0; i < data.Length; i++)
         result[i] = (byte)(~data[i] & 0xFF);

     return result;
 }

 private static int ToIntSafe(string value)
 {
     return int.TryParse(value, out var result) ? result : 0;
 }

 private static List<CoordinatorRecord> ParseRecords(string decoded)
 {
     var fields = decoded.Split(';', StringSplitOptions.None);

     var cleaned = fields
         .Select(f => f.Trim())
         .Where(f => !string.IsNullOrEmpty(f))
         .ToList();

     var records = new List<CoordinatorRecord>();

     for (int i = 0; i <= cleaned.Count - 5; i += 5)
     {
         records.Add(new CoordinatorRecord
         {
             CoordinatorId = cleaned[i],
             PartyMembersPresent = ToIntSafe(cleaned[i + 1]),
             LobbyType = LobbyType2Str(cleaned[i + 2]),
             PlayerRegion = cleaned[i + 3],
             PlayerName = cleaned[i + 4]
         });
     }

     return records;
 }

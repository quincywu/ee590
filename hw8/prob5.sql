select TrackId, Name, AlbumId, MediaTypeId, GenreId, Composer, ( ( Track.Milliseconds / (1000 * 60) ) % 60) || ":" || printf("%02d", ((Track.Milliseconds / 1000) % 60) ) As Durations, Bytes, UnitPrice from Track where Milliseconds > 360000 order by Milliseconds DESC;

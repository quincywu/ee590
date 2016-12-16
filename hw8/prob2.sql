select Track.Name, Album.Title, Artist.Name from Track inner join Album on Track.AlbumId = Album.AlbumId inner join Artist on Album.ArtistId = Artist.ArtistId order by Track.Milliseconds DESC limit 1;
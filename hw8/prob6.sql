select a.Title, count(a.AlbumId) As NumberOfSongs, sum(t.Milliseconds) As AlbumDurations from Album a inner join Track t on a.AlbumId = t.AlbumId group by a.AlbumId order by a.AlbumId asc;

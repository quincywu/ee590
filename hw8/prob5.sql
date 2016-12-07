select a.Title from Track t inner join Album a on t.AlbumId = a.AlbumId where t.Milliseconds > 360000 group by a.AlbumId order by a.AlbumId ASC;

select ar.Name As ArtistName, i.UnitPrice * sum(i.Quantity) As s from Track t inner join InvoiceLine i on t.TrackId = i.TrackId inner join Album a on t.AlbumId = a.AlbumId inner join Artist ar on a.ArtistId = ar.ArtistId group by ar.ArtistId order by i.UnitPrice * sum(i.Quantity) DESC limit 10;
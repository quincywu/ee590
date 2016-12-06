select i.TrackId, t.Name, sum(i.Quantity) As TotalQuantity from InvoiceLine i inner join Track t on i.TrackId = t.TrackId group by i.TrackId order by TotalQuantity DESC limit 10;

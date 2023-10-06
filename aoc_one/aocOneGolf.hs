import Data.List.Split;import Data.Sort;main=do
    str<-readFile"day1.txt";let list=take 3$reverse$sort$map sum$[[read y::Int|y<-x]|x<-splitOn[""]$lines str]
    print$head list;print$sum list

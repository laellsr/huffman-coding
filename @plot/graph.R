compare <- read.csv("comparisons_pq.csv", header=TRUE, sep=",", as.is=TRUE)


title(xlab="CASES", col.lab=rgb(0,0.5,0))
title(ylab="COMPARISONS", col.lab=rgb(0,0.5,0))
title(main="Priority Queue VS PQ with Heap", col.main="black", font.main=2)

plot(compare$CASES, compare$PQ, type="l", xaxt = "n", col="red", ann=FALSE)
lines(compare$PQ_H, type="o", col="blue")
axis(1, at=1:10000, compare$CASES)


plot(compare)
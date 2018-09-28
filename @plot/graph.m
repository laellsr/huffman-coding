% fila de prioridade sem heap
file1 = fopen('comparisons_pq.txt');
A1 = fscanf(file1,'%d %d\n',[2 Inf]);
fclose(file1);

n1 = size(A1,2);

for i=1:1:n1
    x1(i) = A1(1,i);
end

for i=1:1:n1
    y1(i) = A1(2,i);
end

% fila de prioridade com heap
file2 = fopen('comparisons_pqh.txt');
A2 = fscanf(file2,'%d %d\n',[2 Inf]);
fclose(file2);

n2 = size(A2,2);

for i=1:1:n2
    x2(i) = A2(1,i);
end

for i=1:1:n1
    y2(i) = A2(2,i);
end

figure;
plot(x1, y1, 'b-', x2, y2,'r-')
xlim([0 inf]);
ylim([0 inf]);
grid on;
xlabel('size');
ylabel('comparisons');
title('Priority Queue vs Priority Queue with Heap');

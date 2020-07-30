a = csvread('output');
b = csvread('outputD');
figure(1)
hold on
A = scatter3(a(:,1),a(:,2),a(:,3))
scatter3(b(:,1),b(:,2),b(:,3), 'r')


a = csvread('output');
b = csvread('outputD');
figure(1)
scatter3(a(:,1),a(:,2),a(:,3))
figure(2)
scatter3(b(:,1),b(:,2),b(:,3), 'r')


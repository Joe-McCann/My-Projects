points = 1000; %Set the number of data points that will be used throughout this program.
warning('off');

f = {@(x, k)(k.*(x.^0)); @(x, k)sqrt(k.^2-x.^2); @(x, k)(k.^4-x.^4).^(1/4); @(x,k)k/2.*cos(pi.*x./k)+k/2; ...
    @(x,k)9/7*(k/4.*sin(4*pi.*x./k).^2+k./4.*cos(3*pi*x./k)+k/4); @(x,k)((x.^2).^(1/4).*sqrt(k));...
    @(x,k)(exp(x./k-1).*k); @(x,k)(k/2.*(1+abs(sin(2*pi*x./k)))); @(x,k)((x.^2)./(2*k)+k/2)}; %Get the functions that will be used for pans, must be anon functions with 2 parameters

func = size(f);
func = func(1); %Get how many functions are in the input array

shapeNames = {'Square', 'Circle', 'Round Square', 'Cosine', 'Monster', 'Strange Sqrt', 'Exponent'...
    'Raise Sin', 'Parabola'}; %Create an array of names for future legends

radius = 4;
delta = .0001; %Small number for approximating derivatives
x=linspace(-radius, radius, points); 
y=linspace(-radius, radius, points);
[X,Y]=meshgrid(x,y); %Create a mesh of points so that we can visualize the entire pan
Z = NaN(points, points, func); %Create a mesh of values of the temperature. Initialize to NaN so that we can ignore what's outside the pans
sqth = @(a,b)sqrt((a-b).^2+1); %Helper function

for a = 1:func %Do the Heat chart of the other shapes
    figure(a+1) %Create a new chart
    %This is the approximation function for a curve reflected across the y-axis. Section 7 of the write-up includes an explanation
    test = @(u,v)(integral(@(t)(((abs(f{a}(t+delta,radius)-f{a}(t-delta, radius))/(delta*2)).^2+1).^(1/2)./(1+(t-u).^2+(f{a}(t,radius)-v).^2)),-radius,radius)...
        +integral(@(t)(((abs(f{a}(t+delta,radius)-f{a}(t-delta, radius))/(delta*2)).^2+1).^(1/2)./(1+(t-u).^2+(-f{a}(t,radius)-v).^2)),-radius,radius))...
        +atan((f{a}(radius, radius)-v)/sqth(u, radius))/sqth(u, radius)-atan((-f{a}(radius, radius)-v)/sqth(u, radius))/sqth(u, radius)...
        +atan((f{a}(-radius, radius)-v)/sqth(u, -radius))/sqth(u, -radius)-atan((-f{a}(-radius, radius)-v)/sqth(u, -radius))/sqth(u, -radius);
    
    [X,Y]=meshgrid(x,y); % Create a mesh of points
    for i = 1:points %Loop through every point on the plane
        for j = 1:points
            if(f{a}(x(i), radius)<y(j) || -f{a}(x(i),radius)>y(j)) %If it outside the region, skip it
                continue
            end
            val = test(x(i), y(j));
            Z(j, i, a) = test(x(i), y(j)); %Assign the value to the appropriate location in the region
        end
    end
    pcolor(X,Y,Z(:,:,a)); %Create a plot and label it
    c = colorbar;
    c.Label.String = 'Heat Strength';
    shading('interp')
    
    xlabel('X')
    ylabel('Y')
    title(shapeNames{a})
end

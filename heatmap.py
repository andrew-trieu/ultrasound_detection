import numpy as np
import matplotlib.pyplot as plt
 
data = np.random.random(( 20, 25 ))*20
print(data)
plt.imshow( data )
 
plt.title( "2-D Heat Map" )
plt.colorbar()
plt.show()
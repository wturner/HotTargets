class ImageGateway:
    def __init__(self):
        self.image = None
        self.observers = []

    def set_image(self,image):
        self.image = image
        notify_observers()

    def notify_observers():
        for i in range self.observers.size():
            update_observer(self.observers[i],self.image,callback)

    def add_observer(observer):
        self.observers.add(observer)

    def remove_observer(observer):
        self.observers.remove(observer)

    @staticmethod
    def update_observer(observer, image, function):
        observer.update(image,function)

    @classmethod
    def callback():
        print "Image done"

# class ShoppingCart:
#     cart = []

#     def __str__(self):
#         print("Current Items in cart:")
#         for i in len(ShoppingCart.cart):
#             print(f"{ShoppingCart.cart[i][0]} - {ShoppingCart.cart[i][1]}")
#         print(f"Total Quantity: {ShoppingCart.cart.calculate_total()}")

#     def add_item(self, item_name, qty):
#         self.__items = (item_name, qty)
#         ShoppingCart.cart.append(self.__items)

#     def remove_item(self, item_name, qty):
#         self.__items = (item_name, qty)
#         ShoppingCart.cart.remove(self.__items)

#     def calculate_total(self):
#         total_quantity = 0
#         for i in len(ShoppingCart.cart):
#             total_quantity += ShoppingCart.cart[i][1]
#         return total_quantity

# shoppingcart = ShoppingCart()
# shoppingcart.add_item("Papaya", 100)
# shoppingcart.add_item("Guava", 200)
# shoppingcart.add_item("Orange", 150)
# shoppingcart.__str__()

# shoppingcart.remove_item("Orange", 150)
# shoppingcart.__str__()



class ShoppingCart:
    cart = []

    def __str__(self):
        print("Current Items in Cart:")
        for item in ShoppingCart.cart:
            print(f"{item[0]} - {item[1]}")
        print(f"Total Quantity: {self.calculate_total()}")

    def add_item(self, item_name, qty):
        self.__items = (item_name, qty)
        ShoppingCart.cart.append(self.__items)

    def remove_item(self, item_name, qty):
        self.__items = (item_name, qty)
        ShoppingCart.cart.remove(self.__items)

    def calculate_total(self):
        total_quantity = 0
        for item in ShoppingCart.cart:
            total_quantity += item[1]
        return total_quantity

shoppingcart = ShoppingCart()
shoppingcart.add_item("Papaya", 100)
shoppingcart.add_item("Guava", 200)
shoppingcart.add_item("Orange", 150)
shoppingcart.__str__()
print()

shoppingcart.remove_item("Orange", 150)
shoppingcart.__str__()
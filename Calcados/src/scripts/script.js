// NAV LIST MOBILE


const mobileButton = document.querySelector("#mobile-button");

mobileButton.addEventListener("click", () => {
    const navListMobile = document.querySelector("#nav-list-mobile");
    const icon = document.querySelector("#mobile-button-icon");

    navListMobile.classList.toggle("visible-mobile");
    icon.classList.toggle("fa-x");
});


// OPEN OR CLOSED


const openOrClosed = () => {
    const date = new Date;
    const hours = date.getHours();
    const day = date.getDay();

    const conteinerTime = document.querySelector("#time");

    if (hours > 9 && hours < 18 && day != 0) {
        conteinerTime.classList.remove("time-off");
    } else {
        conteinerTime.classList.add("time-off");
    }
};

openOrClosed();

// CART SHOPPING FEATURE


const buttonCartShopping = [...document.querySelectorAll(".fa-cart-shopping")];
const buttonCloseCartShopping = document.querySelector("#close-order");

const toggleCartShopping = () => {
    const cartShopping = document.querySelector("#cart-shopping");
    cartShopping.classList.toggle("visible-cart-shopping");
};

buttonCartShopping.map((button) => {
    button.addEventListener("click", toggleCartShopping);
});

buttonCloseCartShopping.addEventListener("click", toggleCartShopping); 
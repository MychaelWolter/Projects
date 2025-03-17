const mobileButton = document.querySelector("#mobile-button");

mobileButton.addEventListener("click", () => {
    const navListMobile = document.querySelector("#nav-list-mobile");
    const icon = document.querySelector("#mobile-button-icon");

    navListMobile.classList.toggle("visible-mobile");
    icon.classList.toggle("fa-x");
});



const buttonCartShopping = [...document.querySelectorAll(".fa-cart-shopping")];

buttonCartShopping.map((button) => {
    button.addEventListener("click", () => {
        const cartShopping = document.querySelector("#cart-shopping");
        cartShopping.classList.toggle("visible-cart-shopping");
    });
});
import React from "react";
import ModalOrderList from "./ModalOrderList";
import "./Modal.css";

function Modal({ setOpenModal, orders, clearOrder }) {
  const buttonSound = new Audio("./src/assets/components/buttonTwo.mp3");

  return (
    <div className="modalBackground">
      <div className="modalContainer">
        <div className="titleCloseBtn">
          <button
            onClick={() => {
              buttonSound.play();
              clearOrder();
              setOpenModal(false);
            }}
          >
            X
          </button>
        </div>
        <div className="title">
          <h1>Thank you!</h1>
        </div>
        <div className="body">
          <h5>Check the items below to verify your orders.</h5>
        </div>
        <ModalOrderList orders={orders} />
        <div className="footer">
          <button
            onClick={() => {
              buttonSound.play();
              setOpenModal(false);
            }}
            id="editBtn"
          >
            Edit
          </button>
          <button 
            onClick={() => {
              buttonSound.play();
              clearOrder();
              setOpenModal(false);
            }}
            id="doneBtn"
          >
            Done
          </button>
        </div>
      </div>
    </div>
  );
}

export default Modal;

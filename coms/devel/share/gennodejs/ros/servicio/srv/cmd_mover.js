// Auto-generated. Do not edit!

// (in-package servicio.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------


//-----------------------------------------------------------

class cmd_moverRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.comando = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('comando')) {
        this.comando = initObj.comando
      }
      else {
        this.comando = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type cmd_moverRequest
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [comando]
    bufferOffset = _serializer.string(obj.comando, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmd_moverRequest
    let len;
    let data = new cmd_moverRequest(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [comando]
    data.comando = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.comando.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'servicio/cmd_moverRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b71efdf4fdba7903c7ba39340b7325d0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    string comando
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmd_moverRequest(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.comando !== undefined) {
      resolved.comando = msg.comando;
    }
    else {
      resolved.comando = ''
    }

    return resolved;
    }
};

class cmd_moverResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.respuesta = null;
    }
    else {
      if (initObj.hasOwnProperty('respuesta')) {
        this.respuesta = initObj.respuesta
      }
      else {
        this.respuesta = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type cmd_moverResponse
    // Serialize message field [respuesta]
    bufferOffset = _serializer.string(obj.respuesta, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type cmd_moverResponse
    let len;
    let data = new cmd_moverResponse(null);
    // Deserialize message field [respuesta]
    data.respuesta = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.respuesta.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'servicio/cmd_moverResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '20c061e7118b603384c6cab5fe2706ff';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string respuesta
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new cmd_moverResponse(null);
    if (msg.respuesta !== undefined) {
      resolved.respuesta = msg.respuesta;
    }
    else {
      resolved.respuesta = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: cmd_moverRequest,
  Response: cmd_moverResponse,
  md5sum() { return '0d7c1320405ff716cbb9ed56b1e4bf4b'; },
  datatype() { return 'servicio/cmd_mover'; }
};
